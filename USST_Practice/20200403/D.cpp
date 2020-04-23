#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int res[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int maxnum = -INF;
    int minnum = INF;
    int x;
    for(int i = 0; i<n;i++){
        cin>>x;
        maxnum = max(x, maxnum);
        minnum = min(x,minnum);
        res[i] = maxnum - minnum;
    }
    for(int i = 0; i< q; i++){
        cin>>x;
        cout<<res[--x]<<" ";
    }
    return 0;
}