#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[25][25];
long dp[25][25];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x++;
    y++;
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    for(int i = 1; i<=n+1;i++){
        for(int j = 1; j<=m+1 ; j++){
            if(i == 1 && j == 1){
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if((i == x && j == y) || (i == x-1 && j == y-2) || (i == x-1 && j == y+2) || (i == x-2 && j == y-1) || (i == x-2 && j == y+1)
               || (i == x+1 && j == y-2) || (i == x+1 && j == y+2) || (i == x+2 && j == y-1) || (i == x+2 && j == y+1)){
                   dp[i][j] = 0;
               }
        }
    }
    cout<<dp[n+1][m+1];
    return 0;
}