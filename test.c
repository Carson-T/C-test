#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define NumOf_customer 1  
#define NumOf_Service_Window 10  
#define Number_Limits  200
#define Queue_Limits 10

sem_t Full_sem; 
sem_t Empty_sem;  
pthread_mutex_t Mutex;  

int Customer_Number = 0;
int Service_Number = 0;

void *Call_number(void)    
{
    while(1)
    {
        sleep(0.8);
        sem_wait(&Empty_sem); 
        pthread_mutex_lock(&Mutex); 
        if(Customer_Number<Number_Limits){
            Customer_Number++;
        }
        else{
            pthread_mutex_unlock(&Mutex);
            sem_post(&Empty_sem);
            break;
        }
        printf("A customer come, whose number is:%d \n",Customer_Number);
        pthread_mutex_unlock(&Mutex);
        sem_post(&Full_sem);  
    }

}

void *Service(void *id)
{
    while(1)
    {   
        if(Service_Number==Number_Limits)
            break;
        sem_wait(&Full_sem);
        pthread_mutex_lock(&Mutex);
        Service_Number++;
        printf("Service Window %d serve one, whose number is:%d \n",(int)id,Service_Number);
        pthread_mutex_unlock(&Mutex);
        sem_post(&Empty_sem);
        sleep(1);
    }
}

int main()
{
    pthread_t Pro[NumOf_customer];
    pthread_t Con[NumOf_Service_Window];

    int temp1 = sem_init(&Full_sem,0,0);
    int temp2 = sem_init(&Empty_sem,0,Queue_Limits);

    if(temp1&&temp2!=0)
    {
        printf("sem init failed \n");
        exit(1);
    }

    int temp3 = pthread_mutex_init(&Mutex,NULL);

    if(temp3!=0)
    {
        printf("Mutex init failed \n");
        exit(1);
    }

    for(int i=0 ;i<NumOf_customer;i++)
    {
        int temp4 = pthread_create(&Pro[i],NULL,Call_number,NULL);
        if(temp4!=0)
            printf("thread create failed !\n");
    }

    for(int i=0;i<NumOf_Service_Window;i++)
    {
        int temp5 = pthread_create(&Con[i],NULL,Service,(void*)i);
        if(temp5!=0)
            printf("thread create failed !\n");
    }

    for(int i=0;i<NumOf_customer;i++)
        pthread_join(Pro[i],NULL);


    for(int i=0;i<NumOf_Service_Window;i++)
        pthread_join(Con[i],NULL);

    exit(1);
    return 0;
}