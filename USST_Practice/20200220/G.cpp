#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[105][105];
int dp[105][105];

int main(){
    int n,m;
    while(1){
        cin>>n>>m;
        if(n == 0 && m == 0){
            break;
        }
        for(int i =0; i<n ; i++){
            for(int j = 0; j<m; j++){
                scanf("%d",&a[i][j]);
            }
        }
        
    }

    return 0;
}