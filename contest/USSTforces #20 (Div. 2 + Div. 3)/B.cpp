#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k,n,s,p;
    cin>>k>>n>>s>>p;
    long long ans = 1;
    long long last = 1;
    while(1){
        if(ans * p/k*s >= n){
            for(long long i =last ;i <= ans;i++){
                if(i * p/k *s >= n){
                    ans = i;
                    break;
                }
            }
            break;
        }
        last = ans;
        ans<<=1;
    }
    cout<<ans;
    return 0;
}