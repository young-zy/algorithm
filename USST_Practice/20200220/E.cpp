#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

const int mod = 9973;

using namespace std;

long long quickpowmod(long long a,long long b,long long c){
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
    int t;
    cin>>t;
    long long n,b;
    for(int ti = 0; ti < t; ti++){
        cin>>n>>b;
        if(n == 0){
            cout<<0<<endl;
            continue;
        }
        b = quickpowmod(b, 9971, mod);
        cout<<(n * b)%mod<<endl;
    }
    return 0;
}