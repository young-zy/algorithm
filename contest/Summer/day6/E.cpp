#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

long long dp[100005][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    long long count = 0;
    memset(dp,0,sizeof(dp));
    // if(s[s.length()-1] == 1){

    // }
    // dp[s.length()-1][0] = 1;
    // dp[s.length()-1][1] = 0;
    // if(s.length() > 2){
    //     if(s[s.length()-2] == '1' ||s[s.length()-2] == '2' && s[s.length()-1] <= '6'){
    //         dp[s.length()-2][1] = 1;
    //     }
    // }
    if(s[s.length()-1] == '0'){
        dp[s.length()-1][0] = 0;
        dp[s.length()-1][1] = 0;
        dp[s.length()-2][0] = 0;
        dp[s.length()-2][1] = 1;
    }else if(s[s.length()-2] == '1' || s[s.length()-2] == '2' && s[s.length()-1] <= '6'){
        dp[s.length()-1][0] = 1;
        dp[s.length()-1][1] = 0;
        dp[s.length()-2][0] = 1;
        dp[s.length()-2][1] = 1;
    }else{
        dp[s.length()-1][0] = 1;
        dp[s.length()-1][1] = 0;
        dp[s.length()-2][0] = 1;
        dp[s.length()-2][1] = 0;
    }
    for(int i = s.length()-3; i>=0;i--){
        if(s[i]== 0){
            continue;
        }
        if(s[i+1] == '0'){
            dp[i][0] = 0;
        }else{
            dp[i][0] = dp[i+1][0] + dp[i+1][1];
        }
        dp[i][0] %= MOD;
        if((s[i] == '1' || s[i]=='2' && s[i+1] <= '6') && s[i+2]!= '0'){
            dp[i][1] = dp[i+2][0]+ dp[i+2][1];
        }
        dp[i][1] %= MOD;
    }

    cout<<(dp[0][0]+dp[0][1])%MOD;
    return 0;
}