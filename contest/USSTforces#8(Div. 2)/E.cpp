#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int p[5005];

int Find(int x) {
    return p[x] == -1 ? x : p[x] = Find(p[x]);
}

void Un(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx == fy) return;
    p[fx] = fy;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(p,-1,sizeof(p));
    int n,m,s;
    cin>>n>>m>>s;
    int u,v;
    for(int i = 0; i<m;i++){
        cin>>u>>v;
        Un(u,v);
    }
    int ans = 0;
    int count = 0;
    for(int i = 1; i<=n;i++){
        if(p[i] != -1){
            count++;
        }
    }
    cout<<count;
    return 0;
}