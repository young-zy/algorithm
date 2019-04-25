#include<bits/stdc++.h>

using namespace std;

int isPrime(int a);

int main(){
    int m;
    cin>>m;
    int count = 0;
    while(--m && count <10){
        if(isPrime(m)){
            printf("%6d",m);
            count++;
        }
    }
    return 0;
}

int isPrime(int a){
    if(a == 0 || a == 1){
        return 0;
    }else if(a == 2 || a == 3){
        return 1;
    }else if(a % 2 == 0){
        return 0;
    }else{
        for(int i = 3; i<=sqrt(a) ; i+=2){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
    }
}