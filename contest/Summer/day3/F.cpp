#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int x;
    int depth;
};

priority_queue<node> pq;

int limit[200005];
int a[200005];


vector<int> e[200005],dep[200005];

void dfs(int a, int fa, int d ){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1; i<=n ; i++){
        cin>>a[i];
        limit[a[i]+1]++;
    }
    for(int i = 1; i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    return 0;
}
