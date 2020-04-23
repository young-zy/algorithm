#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int n,m;

char a[105][105];


void dfs(int x,int y){
    a[x][y] = '#';
    if(x > 0){
        if(y > 0){
            if(a[x-1][y-1] == '@'){
                dfs(x-1,y-1);
            }
        }
        if(y < m-1){
            if(a[x-1][y+1] == '@'){
                dfs(x-1,y+1);
            }
        }
        if(a[x-1][y] == '@'){
            dfs(x-1,y);
        }
    }
    if(x < n-1){
        if(y > 0){
            if(a[x+1][y-1] == '@'){
                dfs(x+1,y-1);
            }
        }
        if(y < m-1){
            if(a[x+1][y+1] == '@'){
                dfs(x+1,y+1);
            }
        }
        if(a[x+1][y] == '@'){
            dfs(x+1,y);
        }
    }
    if(y > 0){
        if(a[x][y-1] == '@'){
            dfs(x,y-1);
        }
    }
    if(y < m-1){
        if(a[x][y+1] == '@'){
            dfs(x,y+1);
        }
    }
}

int main(){
    int count = 0;
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m ; j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m ;j++){
            if(a[i][j] == '@'){
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}