#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    int sum =0;
    scanf("%d",&input);
    while(input !=0){
        sum += input % 10;
        input /= 10;
    }
    printf("%d",sum);
    return 0;
}