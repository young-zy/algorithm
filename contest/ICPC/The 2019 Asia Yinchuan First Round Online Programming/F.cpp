#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[205];

int d[205][205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ; te++){
        int n,q;
        cin>>n>>q;
        for(int i = 1; i<=n ; i ++){
            cin>>a[i];
        }
        for(int i = 1; i<=n ; i++){
            for(int j = 0; j<=n;j++){
                cin>>d[i][j];
            }
        }
        for(int qe = 0 ;qe < q; qe++){
            int u,v,w;
            cin>>u>>v>>w;
            int temp[205][205];
            for(int i = 1; i<=n ; i++){
                for(int j = 1; j<=n;j++){
                    if(i == j){
                        d[i][j] = 0;
                    }else if(a[i] >w || a[j]>w ){
                        temp[i][j] = INF;
                    }else{
                        temp[i][j] = d[i][j];
                    }
                }
            }
            
        }
    }
    return 0;
}