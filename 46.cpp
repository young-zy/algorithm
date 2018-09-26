#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,U,D;
    int height = 0;
    int time =0;
    scanf("%d %d %d",&N,&U,&D);
    while(1){
        height += U;
        time ++;
        if(height >= N){
            break;
        }
        height -= D;
        time ++;
    }
    printf("%d",time);
    return 0;
}