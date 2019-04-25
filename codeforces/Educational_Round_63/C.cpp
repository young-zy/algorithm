#include<bits/stdc++.h>

using namespace std;

long long x[300005];
long long p[300005];

int main(){
    long n,m;
    cin>>n>>m;
    for(long i = 0; i<n ; i++){
        scanf("%lld",&x[i]);
    }
    long long b = x[1] - x[0];
    for(long i = 2; i<n ; i++){
        b = __gcd(b,x[i]-x[i-1]);
    }
    for(long i = 0; i< m ; i ++){
        scanf("%lld",&p[i]);
        if(b % p[i] == 0){
            cout<<"YES"<<endl;
            cout<<x[0]<<" "<<i+1;
            return 0;
        }
    }
    
    cout<<"NO";
    return 0;
}