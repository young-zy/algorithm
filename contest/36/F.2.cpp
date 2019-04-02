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
    for(int i = 0; i< n ;i++){
        for(int j = 0 ; j< m;j++){
            cin>>a[i][j];
        }
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
        
    }
    cout<<"NO";
    return 0;
}