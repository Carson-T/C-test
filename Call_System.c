#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define NumOf_Service_Window 10  //服务窗口个数
#define Number_Limits  200   //号码上限
#define Queue_Limits 10 //队列上限

sem_t Full_sem;  //表示队列满的个数信号量
sem_t Empty_sem;  //表示队列空位的个数信号量
pthread_mutex_t Mutex;   //互斥锁

int Customer_Number = 0;   //顾客取得的号码
int Service_Number = 0;   //服务号码，永远小于等于Customer_Number

void *Call_number()    
{
    while(1)
    {
        sleep(0.8);
        sem_wait(&Empty_sem);   
        pthread_mutex_lock(&Mutex); 
        if(Customer_Number<Number_Limits){ //顾客取的号码未达到上限
            Customer_Number++;   //customer+1
        }
        else{
            pthread_mutex_unlock(&Mutex);
            sem_post(&Empty_sem);    //否则将减去的空位加回来
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
        if(Service_Number==Number_Limits)   //当服务号码到达上限，跳出循环
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

void main()
{
    pthread_t Pro;   //只有一个生产者，即只有一条队列  
    pthread_t Ser[NumOf_Service_Window];  //服务窗口集合

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

    int temp4 = pthread_create(&Pro,NULL,Call_number,NULL);
    if(temp4!=0)
        printf("thread create failed !\n");


    for(int i=0;i<NumOf_Service_Window;i++)
    {
        int temp5 = pthread_create(&Ser[i],NULL,Service,(void*)i);
        if(temp5!=0)
            printf("thread create failed !\n");
    }

    pthread_join(Pro,NULL);


    for(int i=0;i<NumOf_Service_Window;i++)
        pthread_join(Ser[i],NULL);

    exit(1);
}