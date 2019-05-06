#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[100005];
int b[100005];
int dp[100005];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int m,t;
    cin>>m>>t;

    for(int i = 0; i<m ; i++){
        cin>>a[i]>>b[i];
    }
    for(int i =0 ;i <m;i++){
        int maxnum = 0;
        for(int v= a[i]; v<=t;v++){
            dp[v]  = max(dp[v], dp[v - a[i]]+b[i]);
        }
    }
    cout<<dp[t];
    return 0;
}