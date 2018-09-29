#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0;i<N;i++){
        int h,w;
        scanf("%d %d",&h,&w);
        float std = (h - 100)*0.9*2;
        if(fabs(std - w) < 0.1*std){
            printf("You are wan mei!");
        }else{
            if(std>w){
                printf("You are tai shou le!");
            }else{
                printf("You are tai pang le!");
            }
        }
        if(i != N-1){
            printf("\n");
        }
    }
    return 0;
}