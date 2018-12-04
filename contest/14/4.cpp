#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long x,y;
    long long result = 0;
    scanf("%d %ld %ld",&n,&x,&y);
    long long Low = 3000000000;
    int low_ = 100000;
    for(int i = 2; i<= n;i++){
        result += (n-i)*(n-i+1)/2;
        long low = (1+i)*i*y/2;
        for(int j = i-1 ; j>=2; j--){
            if((j)*(j-1)/2*x + (i-j-1)*(i-j)/2*y < low){
                low = (j)*(j-1)/2*x + (i-j-1)*(i-j)/2*y;
            }
        }
        result += low;
        if(result < Low){
            low_ = i;
            Low = result;
        }
    }
    printf("%d %lld",low_,Low);
    return 0;
}