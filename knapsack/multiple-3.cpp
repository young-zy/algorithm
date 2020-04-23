#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int v[100005];  //cost
int w[100005];  //value
int s[100005];  //limit of each object
int n;          //amount
int m;          //capacity

int dp[100005];
int g[100005];
int q[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i<n ; i++){                         //对于每个物品
        int v,w,s;                                      //v:cost, w:profit, s:amount
        cin>>v>>w>>s;
        memcpy(g,dp,sizeof(dp));
        for(int j = 0; j < v; j++){                     //枚举余数
            int h = 0;
            int t = -1;
            for(int k = j; k<=m ;k+=v){                 //选取k个物品且不能超过背包容量的最优解（循环决策）单调队列优化
                dp[k] = g[k];
                if(h<=t && k-s*v>q[h]){
                    h++;
                }
                if(h<=t){
                    dp[k] = max(dp[k],g[q[h]]+(k-q[h]/v*w));
                }
                while(h < t && g[q[t]] - (q[t] - j)/v*w <= g[k] - (k-j)/v*w){
                    t--;
                }
                q[++t] = k;
            }
        }
    }
    cout<<dp[m];
    return 0;
}