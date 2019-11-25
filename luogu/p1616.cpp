#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int dp[100005];

int a[10005][2];


//完全背包


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,m;
    cin>>t>>m;
    for(int i = 1; i<=m ; i++){
        cin>>a[i][0]>>a[i][1];
    }
    for (int i = 1; i <= m; i++) {
        for(int j = a[i][0]; j <= t ;j++){
            dp[j] = max(dp[j],dp[j-a[i][0]]+a[i][1]);
        }
    }
    cout<<dp[t];
    return 0;
}