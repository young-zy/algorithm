#include<bits/stdc++.h>

using namespace std;

int main(){
    long n,k;
    scanf("%d %d",&n,&k);
    for(long i = 1; i<=n;i++){
        for(long j = 1 ; j < k;j++){
            if(i*j == n){
                printf("%ld",i*k+j);
                return 0;
            }
        }
    }
    return 0;
}