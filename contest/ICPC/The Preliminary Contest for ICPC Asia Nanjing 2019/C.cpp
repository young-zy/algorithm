#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 998244353
#define maxn 105


using namespace std;

long long quick_pow_mod(long long a, long long b, long long c = MOD){
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


long long euler[maxn];

void getEuler(){
    memset(euler,0,sizeof(euler));
    euler[1] = 1;
    for(int i = 2;i <= maxn;i++)
        if(!euler[i])
            for(int j = i;j <= maxn; j += i){
                if(!euler[j])
                    euler[j] = j;
                euler[j] = euler[j] / i * (i-1);
            }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getEuler();
    int t;
    cin>>t;
    /*
    for(int te = 0; te < t ;te++){
        int n;
        cin>>n;
        long long ans = 0;
        for(int i = 1; i<=n;i++){
            long long temp = euler[i];
            ans += ((temp%MOD)*quick_pow_mod(2,temp))%MOD;
        }
        ans *= ans;
        ans %= MOD;
        cout<<ans<<endl;
    }*/

    for(int n = 1;n<=100; n++){
        long long ans = 0;
        for(int i = 0; i<=n ; i++){
            for(int j = 0; j<= n;j++){
                ans += (euler[i] * euler[j] * quick_pow_mod(2,euler[i] * euler[j]));
                //ans %= MOD;
            }
        }
        cout<<n<<": "<<ans<<"\t"<<ans / euler[n]<<endl;
    }

    return 0;
}