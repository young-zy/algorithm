#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int num;
    int length;
    int color;
    node(int _num,int _length){
        num = _num;
        length = _length;
    }
};

int color[100005];

vector<struct node> e[100000];

long long sum = 0;
int flag = -1;
int start = -1;

void dfs(int no,int last){
    if(color[no] == last){
        start = 0;
        start = no;
        return;
    }else{
        if(color[no] == !last){
            return;
        }else{
            color[no] = !last;
            for(auto it = e[no].begin();it != e[no].end();it++){
                dfs(it->num,!last);
            }
            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(color,-1,sizeof(color));
    for(int i = 0; i<n ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[a].push_back(node(b,c));
        e[b].push_back(node(a,c));
    }
    dfs(1,1);
    return 0;
}