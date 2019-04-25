#include<bits/stdc++.h>

using namespace std;

int main(){
    int x,y;
    while(cin>>x>>y){
        int sum[x+5][y+5];
        memset(sum,0,sizeof(sum));
        sum[0][1] = 1;
        for(int i = 1; i<= x+1;i++){
            for(int j = 1;j<=y+1;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1];
            }
        }
        cout<<sum[x+1][y+1]<<endl;
    }
    return 0;
}