#include<bits/stdc++.h>

using namespace std;

long long maxprime(long long a,long long b);

int main(){
    long long num;
    scanf("%lld",&num);
    long long suma = 0;
    long long sumb = 1;
    for(int i = 0;i<num;i++){
        long long tempa,tempb;
        scanf("%lld/%lld",&tempa,&tempb);
        if(tempa != 0){
            tempa *=sumb;
            sumb *=tempb;
            suma*=tempb;
            suma +=tempa;
        }
    }
    long long result = suma/sumb;
    suma -= result *sumb;
    long long a = maxprime(suma,sumb);
    suma /=a;
    sumb /=a;
    if(result != 0){
        printf("%lld",result);
    }
    if(suma !=0){
        if(result != 0){
            printf(" ");
        }
        printf("%lld/%lld",suma,sumb);
    }
    if(result == 0&&suma==0){
        printf("0");
    }
    return 0;
}

long long maxprime(long long a,long long b){
    long long max  = 1;
    for(long long i = 1; i<=min(a,b);i++){
        if(a % i == 0&& b% i == 0){
            max = i;
        }
    }
    return max;
}