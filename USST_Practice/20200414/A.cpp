#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int dp[55][55];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<55 ; i++){
        dp[0][i] = 1;
    }
    dp[1][1] = 1;
    for(int i = 2; i<55;i++){
        for(int j = i;j>=1;j--){
            dp[i][j] = dp[i-j][j]+dp[i][j+1];
        }
    }
    int n;
    int flag = 0;
    while(cin>>n){
        if(flag){
            cout<<endl;
        }else{
            flag = 1;
        }
        cout<<dp[n][1];
    }
    return 0;
}