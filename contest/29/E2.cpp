#include<bits/stdc++.h>

using namespace std;

long long a[1000005][2];

int main(){
    long n;
    long long result = 0;
    scanf("%ld",&n);
    memset(a,0,sizeof(a));
    for(long i = 0; i<n;i++){
        scanf("%lld",&a[i][0]);
    }
    for(long i = n-1;i>=0;i--){
        if(a[i][1] == 0 && a[i][0] <= 0){
            result += a[i][0] * (i+1);
            a[i][1] = 1;
        }
    }
    for(long i = 0; i<n;i++){
        if(a[i][1] == 0){
            result += a[i][0];
        }
    }
    printf("%lld",result);
    return 0;
}