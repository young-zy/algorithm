#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct trie{
    int ch[2],v;
}tr[600005*26];

long long a[25];
long long b[25];

long long dp[25];

long long ans;
long long n,h;

void dfs(long long aa,long long bb, int num){
    if(num == n){
        if(aa >= h &&bb >= h){
            ans++;
        }
        return;
    }
    dfs(aa+a[num],bb,num+1);
    dfs(aa,bb+b[num],num+1);
    dfs(aa+a[num],bb+b[num],num+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 1; te <= t ;te++){
        ans = 0;
        
        cin>>n>>h;
        for(int i = 0; i<n ; i++){
            cin>>a[i];
        }
        for(int i =0 ; i<n ; i++){
            cin>>b[i];
        }
        dfs(0,0,0);
        cout<<"Case #"<<te<<": "<<ans<<endl;
    }
    return 0;
}