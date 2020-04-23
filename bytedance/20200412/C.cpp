#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int n,m;

long long a[1000005];

long long sum = 0;

long long dp[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i<=n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b;
    for(int i = 0; i<m ; i++){
        cin>>b;
        sum += b;
    }
    long long maxnum = 0;
    for(int i = 1; i<=n; i++){
        for(int j = a[i]; j<=sum;j++){
            dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout<<sum - dp[n];
    return 0;
}