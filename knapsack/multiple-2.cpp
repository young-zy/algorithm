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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i<=n ; i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i = 1; i<=n ; i++){                         //对于每个物品
        for(int j = m ; j>=v[i];j--){                   //在背包剩余j容量时的最优解
            for(int k = 0; k<=s[i] && k*v[i] <= j; k++){//选取k个物品且不能超过背包容量的最优解
                dp[j] = max(dp[j], dp[j-v[i]*k]+w[i]*k);
            }
        }
    }
    cout<<dp[m];
    return 0;
}