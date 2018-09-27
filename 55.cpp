#include<bits/stdc++.h>

using namespace std;

int checkPrime(int a);

int main(){
    int input;
    scanf("%d",&input);
    for(int i = 0;i<input;i++){
        int a;
        scanf("%d",&a);
        if(checkPrime(a)){
            printf("Yes");
        }else{
            printf("No");
        }
        if(i != input -1){
            printf("\n");
        }
    }
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