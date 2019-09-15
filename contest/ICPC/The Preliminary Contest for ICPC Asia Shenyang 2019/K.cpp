#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const long long mod = 1000000007;

using namespace std;

long long a[75];
long long f[75];
int b[75];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        map<long long,int> ma;
        map<long long,double> prob;
        int k;
        long long n;
        long long ans = 0;
        cin>>k>>n;
        for(int i = 0; i<k; i++){
            cin>>a[i];
            ans += a[i];
        }
        long long temp = 0;
        for(int i = 0; i<k ; i++){
            cin>>f[i];
            temp += f[i];
            int flag = 0;
            for(int j = i-1;j>=0;j--){
                if(f[j] == f[i]){
                    flag = 1;
                    ma[i-j]++;
                    b[i] = i-j;
                    break;
                }
            }
            if(flag == 0){
                for(int j = k-1;j>=0;j--){
                    if(a[j] == f[i]){
                        ma[i+k-j]++;
                        b[i] = i+k-j;
                        break;
                    }
                }
            }
        }
        if(n <= k){
            long long sn = 0;
            for(int i = 0; i<n ; i++){
                sn += a[i];
            }
            cout<<sn<<endl;
        }else if(n <= 2*k){
            long long sn = 0;
            for(int i = 0; i<k ; i++){
                sn += a[i];
            }
            for(int i = 0; i<n-k;i++){
                sn += f[i];
            }
            cout<<sn<<endl;
        }else{
            long long time = n / k;
            long long num = n % k;
            long long model[75];
            ans += temp;
            temp = 0;
            for(int i = 0; i<k;i++){
                model[i] = f[k-b[i]];
                temp += model[i];
            }
            // for(auto it = ma.begin();it != ma.end();it++){
            //     if(it->second == 0){
            //         prob[it->first] = 0;
            //     }else{
            //         prob[it->first] = (double)it->second/k;
            //     }
            // }
            ans += ((temp%mod) * ((time-2)%mod)) % mod;
            ans %= mod;
            // for(auto it:prob){
            //     ans += num * model[it.first] * it.second;
            // }
            for(int i = 0; i<num;i++){
                ans += model[i];
                ans %= mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}