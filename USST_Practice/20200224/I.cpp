#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    string a,b,c;
    while(cin>>a>>b>>c){
        int flag = 1;
        int dp[a.length()+2][b.length()+2];
        if(a.length()+b.length() != c.length()){
            flag = 0;
            goto _1;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i<= a.length();i++){
            for(int j = 0; j<= b.length();j++){
                if(c[i+j] == a[i]){
                    dp[i+1][j] = dp[i][j] | dp[i+1][j];
                }
                if(c[i+j] == b[j]){
                    dp[i][j+1] = dp[i][j] | dp[i][j+1];
                }
            }
        }
        _1:
        if( flag && dp[a.length()][b.length()]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}