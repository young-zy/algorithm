#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

char a[20][20];

struct node{
    int x,y;
    int length;
    int b[10][10];
    node(int _x,int _y,int _length){
        x = _x;
        y = _y;
        length = _length;
    }
};

stack<struct node> qu;
int flag = 0;
int n,m,t;

void dfs(int x, int y,int length,int b[10][10]){
    if(flag == 1){
        return;
    }
    if(a[x][y] == 'D' && length == t){
        flag = 1;
        return;
    }
    if(length > t){
        return;
    }
    if(x > 0 && a[x-1][y] != 'X' && b[x-1][y] == 0){
        b[x-1][y] = 1;
        dfs(x-1,y,length+1,b);
        b[x-1][y] = 0;
    }

    if(y > 0 && a[x][y-1] != 'X' && b[x][y-1] == 0){
        b[x][y-1] = 1;
        dfs(x,y-1,length+1,b);
        b[x][y-1] = 0;
    }
    if(x < n-1 && a[x+1][y] != 'X' && b[x+1][y] == 0 ){
        b[x+1][y] = 1;
        dfs(x+1,y,length+1,b);
        b[x+1][y] = 0;
    }
    if(y < m-1 && a[x][y+1] != 'X' && b[x][y+1] == 0){
        b[x][y+1] = 1;
        dfs(x,y+1,length+1,b);
        b[x][y+1] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>t;
    int xs,ys,xd,yd;
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j<m;j++){
            cin>>a[i][j];
            if(a[i][j] == 'S'){
                struct node temp(i,j,0);
                memset(temp.b,0,sizeof(temp.b));
                temp.b[i][j] = 1;
                qu.push(temp);
                xs = i; ys = j;
            }
            if(a[i][j] == 'D'){
                xd = i; yd = j;
            }
        }
    }
    if( (int)(t - (fabs(xs-xd) + fabs(ys-yd))) & 1 == 1 ){
        cout<<"No";
    }else{
        int b[10][10] = {0};
        b[xs][ys] = 1;
        dfs(xs,ys,0,b);
        // int flag = 0;
        // while(!qu.empty()){
        //     struct node temp = qu.top();
        //     qu.pop();
        //     int x = temp.x;
        //     int y = temp.y;
        //     if(a[x][y] == 'D' && temp.length == t){
        //         flag = 1;
        //         break;
        //     }
        //     if(temp.length > t){
        //         break;
        //     }
        //     if(x > 0 && a[x-1][y] != 'X' && temp.b[x-1][y] == 0){
        //         struct node newnode(x-1,y,temp.length+1);
        //         memcpy(newnode.b,temp.b,sizeof(temp.b));
        //         newnode.b[x-1][y] = 1;
        //         qu.push(newnode);
        //     }
        //     if(y > 0 && a[x][y-1] != 'X' && temp.b[x][y-1] == 0){
        //         struct node newnode(x,y-1,temp.length+1);
        //         memcpy(newnode.b,temp.b,sizeof(temp.b));
        //         newnode.b[x][y-1] = 1;
        //         qu.push(newnode);
        //     }
        //     if(x < n-1 && a[x+1][y] != 'X' && temp.b[x+1][y] == 0 ){
        //         struct node newnode(x+1,y,temp.length+1);
        //         memcpy(newnode.b,temp.b,sizeof(temp.b));
        //         newnode.b[x+1][y] = 1;
        //         qu.push(newnode);
        //     }
        //     if(y < m-1 && a[x][y+1] != 'X' && temp.b[x][y+1] == 0){
        //         struct node newnode(x,y+1,temp.length+1);
        //         memcpy(newnode.b,temp.b,sizeof(temp.b));
        //         newnode.b[x][y+1] = 1;
        //         qu.push(newnode);
        //     }
        // }
        if(flag == 0){
            cout<<"No";
        }else{
            cout<<"Yes";
        }
    }
    return 0;
}