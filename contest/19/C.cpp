#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

long dp[10][205];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i<=k;i++){
        for(int j = i; j<=n;j++){
            dp[i][j] = dp[i][j-i] + dp[i-1][j-1];
        }
    }
    cout<<dp[k][n];
    return 0;
}