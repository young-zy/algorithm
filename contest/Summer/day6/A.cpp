#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long fast_mod_pow(long long a,long long b,long long c){
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
    long long n;
    scanf("%lld",&n);
    int ans = fast_mod_pow(5,n,1000);
    printf("%03d",ans);
    return 0;
}