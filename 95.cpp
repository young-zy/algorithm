#include<bits/stdc++.h>

using namespace std;

int main(){
    int a;
    scanf("%d",&a);
    double sum = 1;
    for(long long i = 1;i<=a;i++){
        if(i > 50){
            printf("%.8lf",exp(1));
            return 0;
        }
        long long b =1;
        for(long long j = i;j>1;j--){
            b *= j;
        }
        sum+=(double)1/b;
    }
    printf("%.8lf",sum);
    return 0;
}