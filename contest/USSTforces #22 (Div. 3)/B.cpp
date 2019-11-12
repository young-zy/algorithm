#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define int long long

using namespace std;

int a[100005];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i =1 ;i<=n ; i++){
        cin>>a[i];
    }
    int ans = 0;
    int base = 1;
    int t = 0;
    while(base <= n){
        base <<=1;
        t++;
    }
    base >>= 1;
    t--;
    for(int i = 1; i<n;i++){
        while(i+base > n){
            t--;
            base >>=1;
        }
        a[i+base] += a[i];
        ans += a[i];
        a[i] = 0;
        cout<<ans<<endl;
    }   
    return 0;
}