#include<bits/stdc++.h>

using namespace std;

int main(){
    int sum = 0;
    while(1){
        int num;
        scanf("%d",&num);
        if(num<=0){
            break;
        }
        if(num %2 !=0){
            sum += num;
        }
    }
    printf("%d",sum);
    return 0;
}