#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

queue<int> q;

int n,m,s,x,y,s,t;

int g[201][201];        // 邻接矩阵
int pre[201];           // 前驱
int flow[201];          // 到该点的流量

int maxflow;

int bfs(int s, int t){     //s: source  t: target            
    while (!q.empty()){
        q.pop();
    }                   //清空队列

    for(int i = 1; i<=n; i++){
        pre[i]=-1;
    }                   //设置前驱
    pre[s] = 0;         //
    q.push(s);
    flow[s] = INF;      //
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == t){
            break;
        }
        for(int i = 0; i<n ; i++){
            if(g[x][i]>0 && pre[i] == -1){
                pre[i] = x;
                flow[i] = min(flow[x],g[x][i]);
                q.push(i);
            }
        }
    }
    if(pre[t] == -1){
        return -1;
    }else{
        return flow[t];
    }
}

void EK(int s, int t){
    int increase = 0;
    while((increase = bfs(s,t)) != -1){
        int k = t;
        while( k != s ){
            int last = pre[k];      //从后向前寻找
            g[last][k] -= increase;
            g[k][last] += increase;
            k = last;
        }
        maxflow += increase;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}