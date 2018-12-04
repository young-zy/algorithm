#include<bits/stdc++.h>

using namespace std;

int checkPrime(int a);

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int sum = 0;
    int num = 0;
    for(int i = M;i<=N;i++){
        if(checkPrime(i)){
            sum += i;
            num++;
        }
    }
    printf("%d %d",num,sum);
    return 0;
}

int checkPrime(int a){
    if(a == 1){
        return 0;
    }
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