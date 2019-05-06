#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

char ch[105][105];
int r,c;

int dfs(int x,int y){
    if(ch[x][y] != '#'){
        return 0;
    }else{
        ch[x][y] = '$';
        if(x > 0){
            dfs(x-1,y);
        }
        if(x < r){
            dfs(x+1,y);
        }
        if(y>0){
            dfs(x,y-1);
        }
        if(y<c){
            dfs(x,y+1);
        }
        return 1;
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cin>>r>>c;
    
    
    for(int i = 0; i<r;i++){
        getchar();
        for(int j = 0; j< c; j++){
            ch[i][j] = getchar();
        }
    }
    int count  =0;
    for(int i = 0; i< r;i++){
        for(int j = 0; j< c; j ++){ 
            count += dfs(i,j);
        }
    }
    cout<<count;
    return 0;
}