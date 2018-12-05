#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    int sum = 0;
    for(int i = 0;i< 3;i++){
        scanf("%d",&input);
        sum +=input;
    }
    printf("sum=%d",sum);
    return 0;
}