#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin>>n>>m;
    long long ans = 0;
    for (int i = 2; i <= n; i+=2){
        ans += (n-i+1) * (m+1);
    }
    for (int i = 2; i <=m; i+=2){
        ans += (m-i+1) * (n +1);
    }
    for(int i = 2; i <=n;i+=2){
        for(int j = 2; j<=m; j+=2){
            ans += 2*(n-i+1)*(m-j+1);
        }
    }
    cout<<ans;

    return 0;
}