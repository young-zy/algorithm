#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int flag[n+1];
    memset(flag,0,sizeof(flag));
    int dist[n][n];
    for(int i = 0; i<n;i++){
        for(int j = 0 ;j<n;j++){
            scanf("%d",&dist[i][j]);
        }
    }
    flag[1] = 1;
    while(1){
        int count = 0;
        
    }

    return 0;
}