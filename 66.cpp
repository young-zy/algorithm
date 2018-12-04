#include<bits/stdc++.h>

using namespace std;

int checkPrime(int a);

int main(){
    int m,n;
    int maxdivisor = 1;
    int minmultiple = 1;
    scanf("%d %d",&m,&n);
    float b = max(sqrt(m),sqrt(n));
    for(int i = 2; i<=b;){
        if(i == 2){
            while(m%2 == 0 && n%2 ==0){
                maxdivisor *=2;
                minmultiple *=2;
                m /= 2;
                n /= 2;
            }
            i++;
        }else{
            if(!checkPrime(i)){
                i+=2;
                continue;
            }
            while(m%i == 0 && n%i == 0){
                maxdivisor *= i;
                minmultiple *= i;
                m /=i;
                n /=i;
            }
            i+=2;
        }
    }
    minmultiple *= m;
    minmultiple *= n;
    printf("%d %d",maxdivisor,minmultiple);
    return 0;
}

int checkPrime(int a){
    if(a % 2 == 0 && a != 2){
        return 0;
    }
    if(a % 3 == 0 && a != 3){
        return 0;
    }
    if(a == 3){
        return 1;
    }
    for(int i = 3;i <= sqrt(a); i=i+2){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}