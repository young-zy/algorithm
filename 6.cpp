#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    int score;
    int a[5];
    memset(a,0,sizeof(a));
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        scanf("%d",&score);
        if(score>=70){
            if(score>=80){
                if(score >= 90){
                    a[0]++;
                    continue;
                }else{
                    a[1]++;
                    continue;
                }
            }else{
                a[2]++;
            }
        }else{
            if(score >=60 ){
                a[3]++;
            }else{
                a[4]++;
            }
            continue;
        }
    }
    for(int i = 0; i < 5;i++){
        if(i){
            printf(" ");
        }
        printf("%d",a[i]);
    }
    return 0;
}