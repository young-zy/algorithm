#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const long long mod = 1000000009;

using namespace std;

long long quickpowmod(long long a,long long b,long long c=mod){
    // a ^ b mod c
    long long ans = 1;
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
    long long n,m,k;
    cin>>n>>m>>k;
    long long ans = 0;
    if(n < (n-m) *k){
        ans = m;
    }else{
        long long a = n-(n-m)*k;    //完整组的个数
        long long b = a/k;          //完整组的组数
        ans = quickpowmod(2,b+1);
        ans -= 2;     
        ans *= k;
        ans %= mod;
        long long c = m - a;
        ans += c;
        ans %= mod;
        ans += n % k;
    }
    if(ans < 0){
        ans += mod;
    }
    ans %= mod;
    cout<<ans;
    return 0;
}