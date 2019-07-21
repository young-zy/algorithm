#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i  = 0; i< n ; i++){
        for(int j = 0; j<n ; j++){
            cin>>a[i][j];
        }
    }
    int maxnum = 0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            if(a[i][j] == 1){
                if(i>0 && j > 0){
                    a[i][j] = min(min(a[i-1][j-1],a[i][j-1]),a[i-1][j])+1;
                }
            }
            maxnum = max(maxnum,a[i][j]);
        }
    }
    cout<<maxnum;
    return 0;
}