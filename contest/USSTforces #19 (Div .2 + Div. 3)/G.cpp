#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

string ch[1005];
string ch2[1005];

struct node{
    int x,y;
    int rad;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        cin>>ch[i];
        ch2[i] = ch[i];
    }
    deque<struct node> qu;
    for(int i = 1;i<n-1;i++){
        for(int j = 1;j<m-1;j++){
            if(ch[i][j] == '*' && ch[i-1][j] == '*' && ch[i][j-1] == '*' && ch[i+1][j] == '*' && ch[i][j+1] == '*'){
                node no;
                no.x = i;
                no.y = j;
                int rad = 1;
                ch2[i][j] = '$';
                ch2[i][j] = '$';ch2[i-1][j] = '$';ch2[i][j-1] = '$';ch2[i+1][j] = '$';ch2[i][j+1] = '$';
                while(  i-rad >= 1 && i+rad <= n-2 && 
                        j-rad >= 1 && j+rad <= m-2 &&
                        ch[i-1-rad][j] == '*' && ch[i][j-1-rad] == '*' && ch[i+1+rad][j] == '*' && ch[i][j+1+rad] == '*'){
                    ch2[i-1-rad][j] = '$'; ch2[i][j-1-rad] = '$'; ch2[i+1+rad][j] = '$'; ch2[i][j+1+rad] = '$';
                    rad++;
                }
                no.rad = rad;
                qu.push_back(no);
                
            }
        }
    }
    // for(auto no:qu){
    //     int rad = no.rad;
    //     int x = no.x;
    //     int y = no.y;
    //     ch[x][y] = '$';
    //     for(int i = 1; i<=rad ; i++){
    //         ch[x-i][y] = '$';
    //     }
    //     for(int i = 1; i<=rad ; i++){
    //         ch[x+i][y] = '$';
    //     }
    //     for(int i = 1; i<=rad ; i++){
    //         ch[x][y-i] = '$';
    //     }
    //     for(int i = 1; i<=rad ; i++){
    //         ch[x][y+i] = '$';
    //     }
    // }
    // for(int i = 0; i<n ; i++){
    //     cout<<ch[i]<<endl;
    // }
    int flag = 1;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m ; j++){
            if(ch2[i][j] == '*'){
                flag = 0;
                break;
            }   
        }
        if(!flag){
            break;
        }
    }
    if(!flag){
        cout<<"-1";
    }else{
        cout<<qu.size()<<endl;
        for(auto no:qu){
            cout<<no.x+1<<" "<<no.y+1<<" "<<no.rad<<" "<<endl;
        }
    }
    return 0;
}