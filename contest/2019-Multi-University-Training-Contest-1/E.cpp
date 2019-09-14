#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f

using namespace std;

int a[10005][10005];
int visited[100005];

struct node{
    int num;
    int pri;
    bool operator < (struct node n){
        return this->pri < n.pri;
    }
    node(int _a,int _b){
        num = _a;
        pri = _b;
    }
};

priority_queue<struct node,vector<struct node>, greater<struct node> > pq;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t; te++){
        int n,m;
        cin>>n>>m;
        memset(a,INF,sizeof(a));
        for(int i = 0; i<m;i++){
            int x,y,c;
            cin>>x>>y>>c;
            a[x][y] = c;
            a[y][x] = c;
        }
        int flag = 1;
        while(flag == 1){
            memset(visited,0, sizeof(visited));
            pq.push(node(1,1));
            while(!pq.empty()){
                node temp = pq.top();
                visited[temp.num] = 1;
            }
        }
    }
    return 0;
}