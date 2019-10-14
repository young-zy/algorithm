#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int t[2005],c[2005];

struct node {
    int t,c;
    bool operator < (node n){
        if(c == n.c ){
            return t>n.t;
        }
        return c > n.c;
    }
};

long long dp[2005][2005];

priority_queue<node> pq;

node no[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long sum = 0;
    for(int i = 0; i<n ; i ++){
        cin>>no[i].t>>no[i].c;
        pq.push(no[i]);
        dp[i][no[i].t] = no[i].c;
        sum += no[i].c;
    }
    long long ans = INF;
    for(int i = 1; i<=n ; i++){
        long long temp = sum;
        for(int j = no[i].t-1;j >=0;j--){
            
        }
        ans = min(ans,dp[i][0]);
    }
    return 0;
}