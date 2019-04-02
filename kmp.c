#include<stdio.h>

char ch1[10000];
char ch2[10000];
int next[10000];

int find(char * ch1,char * ch2){
    int i = 0;
    while(ch1[i] != '\0' ){
        int j = 0;
        while(ch2[j] != '\0' ){
            if(ch1[i] == ch2[j]){
                j++;
                i++;
            }else{
                j = next[j];
                i++;
            }
        }
        if(ch2[j] == '\0'){
            return i;
        }
    }
    if(ch1[i] == '\0'){
        return -1;
    }
}

void generate(){
    int j = 0;
    int count = 0;
    int i = 0;
    while( ch2[j] != '\0'){
        j++;
        if(ch2[i] == ch2[j]){
            i++;
            count++;
            next[j] = count;
        }else{
            i = 0;
            count = 0;
            if(ch2[j] == ch2[i]){
                count++;
            }
            next[j] = count;
        }
    }
    return;
}

int main(){
    scanf("%s",ch1);
    scanf("%s",ch2);
    
    return 0;
}