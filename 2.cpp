#include<bits/stdc++.h>

using namespace std;

int main(){
    double sum = 0.0;
    int input;
    scanf("%d",&input);
    for(int i = 1;i<=input;i++){
        sum+=sqrt(i);
    }
    sum = floor(sum*100+0.5)/100;
    printf("sum = %.2lf",sum);
    return 0;
}