#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int d[305][305];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m,t;
    cin>>n>>m>>t;
    memset(d,INF,sizeof(d));
    for(int i = 0; i<n ; i++){
        d[i][i] = 0;
    }
    for(int i = 0; i<m ;i++){
        int a,b;
        cin>>a>>b;
        d[a][b] = 1;
        d[b][a] = 1;
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n;j++){
            for(int k = 0; k < n; k++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int flag = 1;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n ; j++){
            if(d[i][j] > t){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        cout<<"Fail";
    }else{
        cout<<"Win";
    }
    return 0;
}