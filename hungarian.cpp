#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const int maxn = 100005;

using namespace std;

struct Edge {
    int to,nxt;
};

Edge edge[maxn];//maxn条边
int ecnt;       //边数
int hd[maxn];   //第一条边存储位置

void connect(int from,int to){  // 将新的边加到链的头部
    Edge &e = edge[++ecnt];     // 
    e.to = to;
    e.nxt = hd[from];
    hd[from] = ecnt;
}

int dfn[maxn];  // 时间戳
int mch[maxn];  // 右侧节点与左侧匹配

bool dfs(int u,int visitime){       // u为点 visitime为时间戳
    for(int i = hd[u];i;i=edge[i].nxt){
        
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,e;
    cin>>n>>m>>e;
    for(int i = 0; i<e ; i++){
        int u,v;
        cin>>u>>v;
        if(u > n || v>m){
            continue;
        }
        connect(u,v);
    }
    return 0;
}