#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define maxn 300005

using namespace std;

int col[maxn];
int cocount[2];
int minans = 0;

vector<int> e[maxn];

int flag = 1;
//0: black 1:white
void dfs(int n,int last){
    if(col[n] == last){
        flag = 0;
        return;
    }else if(col[n] == (last^1)){
        return;
    }else{
        col[n] = last^1;
        cocount[col[n]]++;
        for(int i = 0; i< e[n].size();i++){
            dfs(e[n][i],last^1);
            if(flag == 0){
                return;
            }
        }
    }
    if(flag == 0){
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i = 0; i<m;i++){
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    memset(col,-1,sizeof(col));
    memset(cocount,0,sizeof(cocount));
    for(int i = 1; i<= n;i++){
        int last = 1;
        if(col[i] == -1){
            memset(cocount,0,sizeof(cocount));
            dfs(i,last);
            minans += min(cocount[0],cocount[1]);
        }
        if(flag == 0){
            break;
        }
    }
    
    if(flag == 0){
        cout<<"QAQ";
    }else{
        cout<<minans;
    }
    return 0;
}