#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int dp[500000];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin>>n;
    dp[0] = 0;
    for(int i = 1 ;i<= n ; i++){
        dp[i] = dp[i-1]+1;
        for(int j = 2; j*j <= i;j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
    return 0;
}