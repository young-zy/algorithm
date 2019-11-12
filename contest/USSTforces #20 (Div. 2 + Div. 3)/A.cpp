#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    long long ans = 0;
    long long now = 0;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        now += a[i];
        cout<<now/m<<" ";
        now %= m;
    }
    return 0;
}