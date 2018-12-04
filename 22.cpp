#include<bits/stdc++.h>

using namespace std;

int checkPrime(int a);

int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int sum = 0;
    for(int i = n; i >= 2 && k > 0; i--){
        if(checkPrime(i)){
            if(sum == 0){
                printf("%d",i);
            }else{
                printf("+%d",i);
            }
            sum += i;
            k--;
        }
    }
    printf("=%d",sum);
    return 0;
}

int checkPrime(int a){
    if(a % 2 == 0 && a != 2){
        return 0;
    }
    if(a % 3 == 0 && a != 3){
        return 0;
    }
    for(int i = 3;i <= sqrt(a); i=i+2){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}