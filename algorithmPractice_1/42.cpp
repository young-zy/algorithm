#include<bits/stdc++.h>

using namespace std;

int main(){
    long input;
    int sum = 0;
    int num = 0;
    scanf("%ld",&input);
    while(input != 0){
        sum += input % 10;
        input /= 10;
        num++;
    }
    printf("%d %d",num,sum);
    return 0;
}