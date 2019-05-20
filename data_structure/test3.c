#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Elemtype;

char ch[1000000];

int main(){
    scanf("%s",ch);
    long long len = strlen(ch);
    for(long long i = 0; i<= len;i++){
        if(ch[i] == '@'){
            ch[i] = '\0';
            len = i-1;
            break;
        }
    }
    int flag = 1;
    for(long long i = 0; i< len/2;i++){
        if(ch[i] != ch[len-i]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        printf("Yes");
    }else{
        printf("No");
    }
}