#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    for(int i = 0; i< 3;i++){
        int  temp = num %10;
        if(temp != 0){
            printf("%d",temp);
        }
        num /= 10;
    }
    return 0;
}