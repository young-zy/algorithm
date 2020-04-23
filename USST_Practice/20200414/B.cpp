#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

long long dp[1005];
long long a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i<=n ; i++){
        cin>>a[i];
        dp[i] = 1;
    }
    long long res = 1;
    for(int i = 2;i<=n;i++){
        for(int j = 1; j<i;j++){
            if(a[j] >= a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
    }
    cout<<res<<" ";
    res = 1;
    for(int i = 1; i<= n; i++){
        dp[i] = 1;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1; j<i;j++){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
    }
    cout<<res;
    return 0;
}