#include<bits/stdc++.h>

using namespace std;

int pow2(int a, int b);

int main(){
    int input;
    scanf("%d",&input);
    for(int i = pow2(10,input-1);i<pow2(10,input);i++){
        long sum = 0;
        int temp = i;
        for(int j = input - 1;j>=0;j--){
            sum += pow2((temp / (int)pow2(10,j)),input);
            temp = temp % (int)pow2(10,j);
        }
        if(sum == i){
            printf("%ld\n",sum);
        }
    }
    return 0;
}


int pow2(int a,int b){
    int temp = a;
    for(;b>1;b--){
        a *= temp;
    }
    if(b==0){
        return 1;
    }
    return a;
}