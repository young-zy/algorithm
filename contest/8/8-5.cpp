#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    int teacher[num][2];
    int man[2];
    for(int i = 0; i< num;i++){
        scanf("%d %d",&teacher[i][0],&teacher[i][1]);
    }
    scanf("%d %d",&man[0],&man[1]);
    for(int i = 0;i<num;i++ ){
        while(1){
            teacher[i][0] -= man[1];
            if(teacher[i][0]<=0){
                break;
            }
            man[0] -= teacher[i][1];
            if(man[0] <= 0 ){
                break;
            }
        }
        if(man[0]<0){
            printf("oh shit!");
            return 0;        
        }
    }
    if(man[0]>0){
        printf("yes!!very good");
    }
    return 0;
}