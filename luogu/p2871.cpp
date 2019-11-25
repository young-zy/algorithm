#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

//01背包

int c[100005],w[100005]; //c:代价   w: 收益

int dp[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>c[i]>>w[i];
    }

    for(int i = 1; i<=n ; i++){  //i代表物品
        for(int j = m;j >= c[i] ;j--){ //j代表背包容量, 若j小于当前物品代价则表示无法放入，结束循环
            //dp[j]代表背包容量为j在第i个物品时是否放入的最优解
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    cout<<dp[m];
    return 0;
}