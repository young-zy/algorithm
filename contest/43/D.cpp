#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[40][40];

long long c(int m,int n){
    return a[m][n];
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    memset(a,0,sizeof(a));
    a[0][0] = 1;
    for(int i = 0; i <= 30;i++){
        a[i][0] = 1;
        for(int j = 1; j< i+1;j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    if(k < 6){
        cout<<0;
        return 0;
    }else{
        long res = 0;
        for(int i = 4; i <= n && k-i >= 2 ; i++){
            int j = k-i;
            res += a[n][i] * a[m][j];
        }
        cout<<res;
    }
    return 0;
}