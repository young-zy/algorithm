#include<bits/stdc++.h>

using namespace std;

int main(){
    int hour,minute;
    int flag = 0;
    scanf("%d:%d",&hour,&minute);
    if(hour >= 12){
        flag = 1;
        if(hour>12){
            hour -=12;
        }
    }
    printf("%d:%d",hour,minute);
    if(flag == 0){
        printf(" AM");
    }else{
        printf(" PM");
    }
    return 0;
}