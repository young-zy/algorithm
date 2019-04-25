#include<bits/stdc++.h>

using namespace std;

long dp[205][205];

int main(){
    long n;
    cin>>n;
    int a[n+2];
    for(int i = 1; i<= n ; i++){
        cin>>a[i];
    }
    a[0] = 1;
    a[n +1] = 1;
    for(long l = 2; l <= n+1;l++){
        for(long r = 1; r +l <= n+2 ; r++){
            long maxnum = 0;
            for(int i = r ; i<r + l -1 ; i++){
                maxnum = max(dp[r][i] + dp[i+1][r+l-1] + (long)a[r+l-1] * a[r-1] *a[i],maxnum);
            }
            dp[r][r+l-1] = maxnum;
        }
    }
    long res = 0;
    cout<<dp[1][n+1];
    return 0;
}