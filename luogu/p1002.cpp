#include<bits/stdc++.h>

using namespace std;

int main(){
    int bx,by,hx,hy;
    cin>>bx>>by>>hx>>hy;
    long long dp[40][40];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    dp[hx][hy] = -1;
    if(hx-1 > 0){
        if(hy-2 > 0)dp[hx-1][hy-2] = -1;
        dp[hx-1][hy+2] = -1;
    }
    if(hx-1 > 0){
        if(hy-1 > 0)dp[hx-2][hy-1] = -1;
        dp[hx-2][hy+1] = -1;
    }
    if(hy-2 > 0)dp[hx+1][hy-2] = -1;
    dp[hx+1][hy+2] = -1;
    if(hy-1 > 0)dp[hx+2][hy-1] = -1;
    dp[hx+2][hy+1] = -1;
    for(int i =0 ;i <= bx;i++){
        for(int j = 0; j <= by;j++ ){
            if(dp[i][j] != -1){
                if(i){
                    if(dp[i-1][j] != -1){
                        dp[i][j] += dp[i-1][j];
                    }
                }
                if(j){
                    if(dp[i][j-1] != -1){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
            
        }
    }
    cout<<dp[bx][by];
    return 0;
}