#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin>>n;
    long long a = 1;
    for(long i = 0; i < n ; i++){
        long long temp;
        scanf("%lld",&temp);
        a ^= temp;
    }
    for(long i = 0; i < n-1 ; i++){
        long long temp;
        scanf("%lld",&temp);
        a ^= temp;
    }
    a^=1;
    cout<<a;
    return 0;
}