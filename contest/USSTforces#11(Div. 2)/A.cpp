#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

deque<int> dq[100005];

int a[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,s;
    cin>>n>>m>>k>>s;

    for(int i = 1; i<=n ; i++){
        cin>>a[i];
    }
    int c,d;
    for(int i = 0; i<m ; i++){
        cin>>c>>d;
        dq[c].push_back(d);
        dq[d].push_back(c);
    }
    
    
    return 0;
}