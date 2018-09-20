#include<bits/stdc++.h>

using namespace std;

int checkPrime(int a);

int main(){
    int input;
    scanf("%d",&input);
    if(input == 4){
        printf("4 = 2 + 2");
    }
    if(input == 6){
        printf("6 = 3 + 3");
    }
    for(int i = 3;i < input - 3;i=i+2){
        int j = input - i;
        if(checkPrime(i) && checkPrime(j)){
            printf("%d = %d + %d", input, i, j);
            return 0;
        }
    }
    return 0;
}

int checkPrime(int a){
    if(a % 2 == 0 && a != 2){
        return 0;
    }
    for(int i = 3;i <= a/2; i=i+2){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}