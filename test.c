#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    int minlen=strlen(strs[0]);
    for(int i=1;i<strsSize;i++){
        if(minlen>strlen(strs[i])){
            minlen = strlen(strs[i]);
        }
    }
    printf("%d",minlen);
    int num = 0;
    char c;
    for(int i=0;i<minlen;i++){
        // printf("%s",strs[0]);
        c = strs[0][i];
        // printf("%c\n",c);
        for(int j=1;j<strsSize;j++){
            // printf("%c\n",strs[j][i]);
            if(c!=strs[j][i]){
                i = -1;
                break;
            }
        }
        if(i==-1)
            break;
        num++;
    }
    if(num>0){
        char * result = (char*)malloc(sizeof(char)*(num+1));
        for(int i=0;i<num;i++){
            result[i] = strs[0][i];
        }
        result[num] = '\0';
        return result;
    }else{
        return "";
    }
    
}

int main(){
    // char *input[] = {"flower","flow","flight"};
    // char *s = longestCommonPrefix(input,3);
    // printf("%s",s);
    if('{'){
        printf("%d",1);
    }
    return 0;
}