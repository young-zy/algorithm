#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    int a[3];
    int count = 1;
    if(input == 495){
        printf("1: 954 - 459 = 495");
    }
    while(input != 495){
        for(int i =0;i<3;i++){
            a[i] = input % 10;
            input /= 10;
        }
        sort(a,a+3);
        int max = a[2]*100 +a[1]*10 +a[0];
        int min = a[0]*100 +a[1]*10 +a[2];
        input = max- min;
        printf("%d: %d - %d = %d",count,max,min,input);
        if(input == 0){
            return 0;
        }
        if(input != 495){
            printf("\n");
        }
        count++;
    }
    return 0;
}