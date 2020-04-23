#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    int to, len;
    node(int _to, int _len){
        to = _to;
        len = _len;
    }

    bool operator < (node no) const{
        return len < no.len;
    }
};

deque<int> dq[200005];
int flag[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    set<node> se;
    int u,v,w;
    for(int i = 0; i<m ; i++){
        cin>>u>>v>>w;
        
    }
    return 0;
}