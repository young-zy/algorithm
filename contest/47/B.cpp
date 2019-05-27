#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

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
    int n;
    cin>>n;
    long long m,p;
    cin>>m>>p;
    long long res = 1;
    for(long long i = 1; i<= n ;i++){
        for(long long j = 1; j<= n;j++){
            for(long long k = 1; k<=n;k++){
                long long gcd = __gcd(i,j);
                long long boolean;
                if(gcd % k == 0)
                    boolean = 1;
                else
                    boolean = 0;
                res =(res%p * quick_pow_mod(m,gcd*boolean,p))%p;
            }
        }
    }
    cout<<res;
    return 0;
}