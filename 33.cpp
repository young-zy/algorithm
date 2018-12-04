#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    char ch;
    scanf("%d %c",&input,&ch);
    int sum = 0;
    int temp;
    int i;
    for(i = 1; sum <=input; i++){
        if(i == 1){
            temp = 1;
            sum += temp;
        }else{
            temp = 2 * (2 * i - 1);
            sum += temp;
        }
    }
    sum -= temp;
    int unused = input - sum;
    i = i-2;
    for(int j = i;j>0;j--){
        for(int k = 0;k < (2 * i - 1 - (2 * j - 1))/2;k++){
            printf(" ");
        }
        for(int k = 0;k < 2 * j - 1;k++){
            printf("%c",ch);
        }
        printf("\n");
    }
    for(int j = 2;j<=i;j++){
        for(int k = (2 * i - 1 - (2 * j - 1))/2;k > 0;k--){
            printf(" ");
        }
        for(int k = 0;k < 2 * j - 1;k++){
            printf("%c",ch);
        }
        printf("\n");
    }
    printf("%d",unused);
    return 0;
}