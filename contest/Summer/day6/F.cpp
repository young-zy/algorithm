#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

char ch[10][10];

struct node{
    int x;
    int y;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
    bool operator = (struct node n){
        if(n.x == x && n.y == y){
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node* start;
    struct node* end;
    struct node *no;
    for(int i = 0; i< 10 ; i ++){
        for(int j = 0 ; j< 10;j++){
            cin>>ch[i][j];
            if(ch[i][j] == 'S'){
                start = new node(i,j);
            }
            if(ch[i][j] == 'T'){
                end = new node(i,j);
            }
            if(ch[i][j] == 'L'){
                no = new node(i,j);
            }
        }
    }
    int ans = fabs(start->x -end->x) + fabs(start->y - end->y);
    if(start->x == end->x && start->x == no->x){
        int a = start->y;
        int b = end->y;
        int c = no->y;
        if(a > b){
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(a< c && c<b){
            ans += 2;
        }
    }
    if(start->y == end->y && start->y == no->y){
        int a = start->x;
        int b = end->x;
        int c = no->x;
        if(a > b){
            a ^= b;
            b ^= a;
            a ^= b;
        }
        if(a< c && c<b){
            ans += 2;
        }
    }
    cout<<ans;
    return 0;
}