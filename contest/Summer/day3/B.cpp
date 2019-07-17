#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 1000000000

using namespace std;

long long fast_pow_mod(long long a, long long b, long long c){
    long ans = 1;
    a %= c;
    while(b){
        if(b & 1){
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a*a) % c;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k,n;
    cin>>k>>n;
    long long ans = fast_pow_mod(n,k,MOD);
    ans -= fast_pow_mod(n-1,k-1,MOD) * (n % MOD);
    ans %= MOD;
    if(ans < 0){
        ans += MOD;
    }
    cout<<ans;
    return 0;
}