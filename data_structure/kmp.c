#include<stdio.h>
#include<stdlib.h>

void prefixtable(char pattern[], int prefix[], int n){
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i<n){
        if(pattern[i] == pattern[len]){
            len++;
            prefix[i] = len;

        }else{
            if(pattern[i] == pattern[0]){
                prefix[i] = 1;
            }else{
                prefix[i] = 0;
            }
            
        }
        i++;
    }
}

int main(){

    return 0;
}