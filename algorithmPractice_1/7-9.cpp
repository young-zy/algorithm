#include<bits/stdc++.h>

using namespace std;

int main(){
    int sum = 0;
    int count = 0;
    for(int i = 2; i < 300;i +=2){
        if(count == 5){
            printf("\n");
            count = 0;
        }
        if(i % 7 == 0){
            printf("%6d",i);
            sum += i;
            count++;
            continue;
        }
        if(i % 17 == 0){
            sum += i;
            printf("%6d",i);
            count++;
        }
    }
    printf("\nsum=%d",sum);
    return 0;
}