#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[105];

int dp[105][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    memset(dp,0,sizeof(dp));
    if(a[n-1]%2){
        dp[n-1][0] = a[n-1];
        dp[n-1][1] = 0;
    }else{
        dp[n-1][0] = 0;
        dp[n-1][1] = a[n-1];
    }
    for(int i = n-2; i>=0 ; i--){
        if(a[i] % 2){
            dp[i][0] = max(dp[i+1][1]+a[i],dp[i+1][0]);
            dp[i][1] = max(a[i]+dp[i+1][0],dp[i+1][1]);
        }else{
            if(dp[i+1][0] %2){
                dp[i][0] = dp[i+1][0]+a[i];
            }
            dp[i][1] = dp[i+1][1]+a[i];
        }
    }
    cout<<dp[0][0];
    return 0;
}