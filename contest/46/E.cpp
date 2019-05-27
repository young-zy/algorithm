#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

//C(n,m)=C(n-1,m-1)+C(n-1,m)

long c[1305][1305];

int mod = 10007;

long quick_pow(long a,long b,long c = mod){
    long ans = 1;
    a %= c;
    while(b){
        if(b & 1){
            ans = (ans%c) * (a%c) % c;
        }
        b >>= 1;
        a = (a%c)*(a%c)%c;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long a,b;
    long k,n;
    c[0][0]=1;
    for(long i=1;i<=1100;i++){
        c[i][0]=1,c[i][i]=1;
        for(long j=1;j<i;j++){
	        c[i][j]=(c[i-1][j]%mod+c[i-1][j-1]%mod)%mod;
		}
    }
    while(~scanf("%ld %ld %ld %ld",&a,&b,&k,&n)){
        long long res;
        //cout<<c[k][n]<<" "<<quick_pow(a,n,mod)<<" "<<quick_pow(b,k-n,mod)<<endl;
        res =((long long)c[k][n]*quick_pow(a,n,mod)*quick_pow(b,k-n,mod))%mod;
        printf("%ld\n",res);
    }
    return 0;
}
