#include<stdio.h>
#include<stdlib.h>

long long Va[100000];
long endpos = 0;


int output(){
    for(long i = 0; i <= endpos ; i++){
        printf("%lld ",Va[i]);
    }
    printf("\n");
}

int insert(long long x){
    if(endpos >= 99999){
        return 0;   
    }
    int pos = 0;
    while(x < Va[pos]){
        pos++;
    }
    for(long i = endpos; i>=pos; i-- ){
        Va[i+1] = Va[i];
    }
    Va[pos] = x;
    endpos++;
    return 1;
}



int main(){
    long n;
    scanf("%lld",&n);
    for(long i = 0; i< n ; i++){
        long long temp;
        scanf("%lld",&temp);
        insert(temp);
        output();
    }
    return 0;
}