#include<bits/stdc++.h>

using namespace std;

struct state{
    int x;
    int y;
    int turn;
    int heading;
};

int main(){
    stack<state> st;
    int n,m;
    cin>>n>>m;
    char a[n][m];
    int startx,starty;
    for(int i = 0; i< n ;i++){
        for(int j = 0 ; j< m;j++){
            cin>>a[i][j];
            if(a[i][j] == 'S'){
                startx = i;
                starty = j;
            }
        }
    }   
    if(startx > 0 && a[startx-1][starty] != '*'){
        struct state temp;
        temp.x = startx-1;
        temp.y = starty;
        temp.heading = 0;
        temp.turn = 0;
        st.push(temp);
    }
    if(startx < n-1 && a[startx+1][starty] != '*'){
        struct state temp;
        temp.x = startx+1;
        temp.y = starty;
        temp.heading = 2;
        temp.turn = 0;
        st.push(temp);
    }
    if(starty > 0 && a[startx][starty-1] != '*'){
        struct state temp;
        temp.x = startx;
        temp.y = starty-1;
        temp.heading = 3;
        temp.turn = 0;
        st.push(temp);
    }
    if(startx < m-1  && a[startx][starty+1] != '*'){
        struct state temp;
        temp.x = startx;
        temp.y = starty+1;
        temp.heading = 1;
        temp.turn = 0;
        st.push(temp);
    }



    while(!st.empty()){
        struct state temp = st.top();
        st.pop();
        int x = temp.x;
        int y = temp.y;
        if(temp.turn > 2){
            continue;
        }
        if(a[x][y] == 'T'){
            cout<<"YES";
            return 0;
        }
        if(x-1>=0 && a[x-1][y] != '*' && temp.heading != 2){
            struct state no;
            no.x = x-1;
            no.y = y;
            no.heading = 0;
            if(temp.heading != 0){
                no.turn = temp.turn + 1;
            }else{
                no.turn = temp.turn;
            }
            st.push(no);
        }
        if(y+1<=m-1 && a[x][y+1] != '*' &&temp.heading != 3){
            struct state no;
            no.x = x;
            no.y = y+1;
            no.heading = 1;
            if(temp.heading != 1){
                no.turn = temp.turn + 1;
            }else{
                no.turn = temp.turn;
            }
            st.push(no);
        }
        if(x+1<=n-1 && a[x+1][y] != '*' && temp.heading != 0){
            struct state no;
            no.x = x+1;
            no.y = y;
            no.heading = 2;
            if(temp.heading != 2){
                no.turn = temp.turn + 1;
            }else{
                no.turn = temp.turn;
            }
            st.push(no);
        }
        if(y-1>=0 && a[x][y-1] != '*' && temp.heading != 1){
            struct state no;
            no.x = x;
            no.y = y-1;
            no.heading = 3;
            if(temp.heading != 3){
                no.turn = temp.turn + 1;
            }else{
                no.turn = temp.turn;
            }
            st.push(no);
        }
    }
    
    cout<<"NO";
    return 0;
}