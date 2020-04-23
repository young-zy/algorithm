#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int n;          //amount
int m;          //capacity

int dp[100005];

struct node{
    int v,w;
};

vector<node> ve;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int v,w,s;
    for(int i = 1; i<=n ; i++){
        cin>>v>>w>>s;
        for(int k = 1; k<=s;k*=2){
            s -= k;
            ve.push_back({v*k,w*k});
        }
        if(s>0){
            ve.push_back({s*v,w*s});
        }
    }
    for(auto it:ve){
        for(int j = m; j>=it.v; j--){
            dp[j] = max(dp[j], dp[j-it.v]+it.w);
        }
    }
    cout<<dp[m];
    return 0;
}