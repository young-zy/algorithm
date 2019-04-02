#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long Va[100000];
long endpos = 0;

long long int_pow(long a, int b){
    long long res = 1;
    for(int i = 0 ; i < b;i++){
        res *= a;
    }
    return res;
}

int input(long long * x){
    long long result = 0;
    char ch[10000];
    int i = 0;
    ch[i] = getchar();
    while(ch[i] == ' ' || ch[i] == '\n'){
        ch[i] = getchar();
    }
    if(ch[i] < '0' || ch[i] > '9'){
        return 0;
    }
    while(ch[i] != ' ' && ch[i] != '\n'){
        if(ch[i] < '0' || ch[i] > '9'){
            return 0;
        }
        i++;
        ch[i] = getchar();
    }
    i--;
    for(int j = 0;i>=0;i--,j++){
        result += (ch[j] - '0') * int_pow(10,i);
    }
    *x = result;
    return 1;
}

int output(){
    for(long i = 0; i < endpos ; i++){
        printf("%lld ",Va[i]);
    }
    printf("\n");
}

int insert(long long x){
    if(endpos >= 99999){
        return 0;   
    }
    int pos = 0;
    while(x > Va[pos]){
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
    for(long i = 0 ;i < 100000;i++){
        Va[i] = 0x7fffff;
    }
    long n;
    while(n != -1){
        for(long i = 0; i< n ; i++){
            long long temp;
            while(!input(&temp)){
                printf("ERROR , PLS ENTER NUMBER AGAIN!\n");
            }
            insert(temp);
            output();
        }
        scanf("%lld",&n);
    }
    
    return 0;
}