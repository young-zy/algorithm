#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

long long dp[105][505];

long long c[105];
long long w[105];

//完全背包

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s;
    cin>>n>>m>>s;
    for(int i = 0; i<n ;i++){
        cin>>c[i]>>w[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i = 0; i< n;i++){
        for(int j = m; j>=1;--j){
            for(int k = s; k >=0;k--){
                if(k>=c[i]){
                    dp[j][k] = max(dp[j-1][k-c[i]]+w[i],dp[j][k]);
                }else{
                    dp[j][k] = max(dp[j][k],dp[j][k]);
                }
            }
        }
    }
    long long res = 0;
    for(int i = 1; i<=m;i++){
        res = max(res,dp[i][s]);
    }
    cout<<res;
    return 0;
}