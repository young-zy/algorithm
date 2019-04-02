#include<bits/stdc++.h>

using namespace std;

struct node{
    int x;
    int y;
    int state;
};

int main(){
    int n,m;
    cin>>n>>m;
    char a[n][m];
    node start;
    queue<node> qu;
    for(int i = 0 ; i< n ;i++){
        getchar();
        for(int j = 0 ;j < m ; j++){
            a[i][j] = getchar();
            if(a[i][j] == 'S'){
                start.x = i;
                start.y = j;
            }
        }
    }
    qu.push(start);
    while(!qu.empty()){
        for(int i  = 0; i < n ;i++){
            for(int j = 0; j < m ; j++){
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
        node temp = qu.front();
        qu.pop();
        if(temp.x >=1 && (temp.state != 2 && a[temp.x][temp.y] == 'S')){
            if(a[temp.x-1][temp.y] == 'T' && (temp.state == 0 || a[temp.x][temp.y] <=1)){
                cout<<"YES";
                return 0;
            }
            if(a[temp.x-1][temp.y] != '*'){
                node n;
                n.state = 0;
                n.x = temp.x-1;
                n.y = temp.y;
                if(a[temp.x][temp.y] == 'S'){
                    a[temp.x-1][temp.y] = 0;
                    n.state = 0;
                    n.x = temp.x-1;
                    n.y = temp.y;
                    qu.push(n);
                }else if(temp.state != 0){
                    a[temp.x-1][temp.y] = a[temp.x][temp.y]+1;
                    if(a[temp.x-1][temp.y] != 3){
                        qu.push(n);
                    }
                }else{
                    a[temp.x-1][temp.y] = a[temp.x][temp.y];
                    qu.push(n);
                }
            }
        }
        if(temp.x < n-1 && (temp.state != 0 && a[temp.x][temp.y] == 'S' ) ){
            if(a[temp.x+1][temp.y] == 'T' && (temp.state == 0 || a[temp.x][temp.y] <=1)){
                cout<<"YES";
                return 0;
            }
            if(a[temp.x+1][temp.y] != '*'){
                node n;
                n.state = 2;
                n.x = temp.x+1;
                n.y = temp.y;
                if(a[temp.x][temp.y] == 'S'){
                    a[temp.x+1][temp.y] = 0;
                    n.state = 2;
                    n.x = temp.x+1;
                    n.y = temp.y;
                    qu.push(n);
                }else if(temp.state != 2){
                    a[temp.x+1][temp.y] = a[temp.x][temp.y]+1;
                    if(a[temp.x+1][temp.y] != 3){
                        qu.push(n);
                    }
                }else{
                    a[temp.x+1][temp.y] = a[temp.x][temp.y];
                    qu.push(n);
                }
            }
        }
        if(temp.y >= 1 && (temp.state != 1)&& a[temp.x][temp.y] == 'S'){
            if(a[temp.x][temp.y-1] == 'T' && (temp.state == 3 || a[temp.x][temp.y] <=1)){
                cout<<"YES";
                return 0;
            }
            if(a[temp.x][temp.y-1] != '*' ){
                node n;
                n.state = 3;
                n.x = temp.x;
                n.y = temp.y-1;
                if(a[temp.x][temp.y] == 'S'){
                    a[temp.x][temp.y-1] = 0;
                    n.state = 3;
                    n.x = temp.x;
                    n.y = temp.y-1;
                    qu.push(n);
                }else if(temp.state != 3){
                    a[temp.x][temp.y-1] = a[temp.x][temp.y]+1;
                    if(a[temp.x][temp.y-1] != 3){
                        qu.push(n);
                    }
                }else{
                    a[temp.x][temp.y-1] = a[temp.x][temp.y];
                    qu.push(n);
                }
            }
        }
        if(temp.y < m-1 && (temp.state != 3 && a[temp.x][temp.y] == 'S')){
            if(a[temp.x][temp.y+1] == 'T' && (temp.state == 1 || a[temp.x][temp.y] <=1)){
                cout<<"YES";
                return 0;
            }
            if(a[temp.x][temp.y+1] != '*'){
                node n;
                n.state = 1;
                n.x = temp.x;
                n.y = temp.y+1;
                if(a[temp.x][temp.y] == 'S'){
                    a[temp.x][temp.y+1] = 0;
                    n.state = 1;
                    n.x = temp.x;
                    n.y = temp.y+1;
                    qu.push(n);
                }else if(temp.state != 1){
                    a[temp.x][temp.y+1] = a[temp.x][temp.y]+1;
                    if(a[temp.x][temp.y+1] != 3){
                        qu.push(n);
                    }
                }else{
                    a[temp.x][temp.y+1] = a[temp.x][temp.y];
                    qu.push(n);
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}