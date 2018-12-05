#include<bits/stdc++.h>

using namespace std;

int main(){
    int randomnum, N;
    scanf("%d %d",&randomnum,&N);
    int i = 0;
    int input;
    scanf("%d",&input);
    if(input < 0){
        printf("Game Over");
        return 0;
    }
    while(input != randomnum && i < N){
        i++;
        if(input > randomnum){
            printf("Too big\n");
        }else{
            printf("Too small\n");
        }
        if( i == N){
            break;
        }
        scanf("%d",&input);
        if(input < 0 ){
            printf("Game Over");
            return 0;
        }
    }
    if(input != randomnum){
        printf("Game Over");
    }else if(i >= 3){
        printf("Good Guess!");
    }else if(i > 0){
        printf("Lucky You!");
    }else{
        printf("Bingo!");
    }
    return 0;
}