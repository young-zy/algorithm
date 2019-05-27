#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 91948941

using namespace std;

long long quick_pow_mod(long long a, long long b, long long c){
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
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        long long n;
        cin>>n;
        if(n == 1){
            cout<<1<<endl;
            continue;
        }
        long long res = ((((n-1)% MOD)* quick_pow_mod(2LL,n-2,MOD))% MOD);
        res = (res + quick_pow_mod(2,n-1,MOD)) % MOD;
        cout<<res<<endl;
    }
    
    return 0;
}