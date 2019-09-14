#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[1005];

int dp[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    int count = 0;
    set<int> se;
    for(int i = 0; i<n ; i++){
        se.insert(a[i]);
        if(se.size()>k){
            count++;
            se.clear();
            se.insert(a[i]);
        }
    }
    count++;
    cout<<count<<endl;
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i<n ; i++){
        se.clear();
        for(int j = i ; j>=0;j--){
            se.insert(a[j]);
            if(se.size() <= k){
                dp[i] = min(dp[i],dp[j-1]+(int)se.size());
            }else{
                break;
            }
        }
    }
    cout<<dp[n-1];
    return 0;
}