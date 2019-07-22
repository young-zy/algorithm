#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define mod 1000000007

using namespace std;

 long long f(long long n){
     long long ans;
     long long a = n;
     long long b = a+1;
     long long c = 2*a+1;
    if(a % 2 == 0){
        a/=2;
    }else{
        b/=2;
    }
    if(a % 3 == 0){
        a/=3;
    }else if(b % 3 == 0){
        b /=3;
    }else{
        c /=3;
    }
    ans = ((((a%mod)*(b%mod))% mod) *(c%mod))%mod;
    return ans;
}

 long long b( long long n, long long d){
     long long ans= f(n/d)-f(n/(d+1));
    if(ans < 0){
        ans += mod;
    }
    return ans;
}

 long long a(long long n){
     long long ans = 0;
    for(long long i = 1; i<=sqrt(n) ; i++){
        ans = ans + ((i%mod)*(b(n,i)%mod))%mod;
        ans %= mod;
    }
    return ans;
}

long long c( long long n){
     long long ans = 0;
    for( long long i = 1; i<=(n/((long long)sqrt(n)+1)); i++){
        ans = ans + ((((i%mod) * (i%mod))%mod) * ((n/i)%mod))%mod;
        ans %= mod;
    }
    return ans;
}

long long sigma2(long long n){
    return (c(n)+a(n))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n,m;
    cin>>n>>m;
    long long x = ((n*(n+1)>>1)%mod * n%mod)%mod;
    long long y = ((m*(m+1)>>1)%mod * m%mod)%mod;
    x -= sigma2(n);
    if(x < 0){
        x+=mod;
    }
    y -= sigma2(m);
    if(y < 0){
        y+=mod;
    }
    cout<<(x*y)%mod;
    return 0;
}