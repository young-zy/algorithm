#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int dp[105][105];
int a[105];
int mod = 19260817;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    memset(dp,0,sizeof(dp));
    dp[0][s] = 1;
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<=n;j++){
            if(j > 1)
                dp[i][j] += dp[i-1][j-1];
            if(j < n)
                dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= 19260817;
        }
    }
    cout<<dp[m][t];
    return 0;
}