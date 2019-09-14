#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005];
int flag[100005];
int b[100005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    queue<int> qu;
    for(int i = 1; i<=n ; i++){
        cin>>a[i];
    }
    for(int i = 0; i<m ; i++){
        cin>>b[i];
        if(b[i] < qu.size()){

        }else{
            
        }
        qu.push(a[b[i]]);
        flag[b[i]] = 1;
    }
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    for(int i = 1; i<=n ; i++){
        if(flag[i] != 1){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}