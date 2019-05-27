#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int a[15][15];

struct node{
    int x,y,length;
    node(int _x,int _y,int _length){
        x = _x;
        y = _y;
        length = _length;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    for(int i = 0; i< t ;i++){
        queue<struct node> qu;
        char x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1 -= 'A';
        y1 -= '1';
        x2 -= 'A';
        y2 -= '1';
        int flag = 0;
        memset(a,0,sizeof(a));
        struct node temp(x1,y1,0);
        int length = -1;
        qu.push(temp);
        while(!qu.empty()){
            struct node temp = qu.front();
            qu.pop();
            a[temp.x][temp.y] = 1;
            if(temp.x == x2 && temp.y == y2){
                flag = 1;
                length = temp.length;
                break;
            }
            if(temp.x > 0){
                if(temp.y > 1 && a[temp.x-1][temp.y-2] == 0){
                    struct node newtemp(temp.x-1,temp.y-2,temp.length+1);
                    qu.push(newtemp);
                }
                if(temp.y < 7 && a[temp.x-1][temp.y+2] == 0){
                    struct node newtemp(temp.x-1,temp.y+2,temp.length+1);
                    qu.push(newtemp);
                }
            }
            if(temp.x > 1){
                if(temp.y > 0 && a[temp.x-2][temp.y-1] == 0){
                    struct node newtemp(temp.x-2,temp.y-1,temp.length+1);
                    qu.push(newtemp);
                }
                if(temp.y < 8 && a[temp.x-2][temp.y+1] == 0){
                    struct node newtemp(temp.x-2,temp.y+1,temp.length+1);
                    qu.push(newtemp);
                }
            }
            if(temp. x < 7){
                if(temp.y > 0 && a[temp.x+2][temp.y-1] == 0){
                    struct node newtemp(temp.x+2,temp.y-1,temp.length+1);
                    qu.push(newtemp);
                }
                if(temp.y < 8 && a[temp.x+2][temp.y+1] == 0){
                    struct node newtemp(temp.x+2,temp.y+1,temp.length+1);
                    qu.push(newtemp);
                }
            }
            if(temp. x < 8){
                if(temp.y > 1 && a[temp.x+1][temp.y-2] == 0){
                    struct node newtemp(temp.x+1,temp.y-2,temp.length+1);
                    qu.push(newtemp);
                }
                if(temp.y < 7 && a[temp.x+1][temp.y+2] == 0){
                    struct node newtemp(temp.x+1,temp.y+2,temp.length+1);
                    qu.push(newtemp);
                }
            }
        }
        if(flag == 0){
            cout<<-1<<endl;
        }else{
            cout<<length<<endl;
        }
    }
    return 0;
}