#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int v[100005];  //cost
int w[100005];  //value
int n;          //amount
int m;          //capacity

int dp[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i<=n ; i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1; i<=n ; i++){
        for(int j = m ; j>=v[i];j--){
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m];
    return 0;
}