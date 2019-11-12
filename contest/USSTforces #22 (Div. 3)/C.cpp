#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int ch[5005][5005];
int sum[5005][5005] = {0};

long long a(int x1, int y1,int x2,int y2){
    return (long long)sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    memset(ch,0,sizeof(ch));
    memset(sum,0,sizeof(sum));
    for(int i = 1; i<=n ; i++){
        for(int j = 1; j<=m; j++){
            scanf(" %c",&ch[i][j]);
            ch[i][j] -= '0';
        }
    }
    for(int i = 0; i <= 5000;i++){
        for(int j = 0; j<=5000;j++){
            sum[i][j] = (long long)sum[i-1][j] + sum[i][j-1]-sum[i-1][j-1] + ch[i][j];
        }
    }
    // for(int i = 0; i<=n ; i++){
    //     for(int j = 0; j<=m ; j++){
    //         cout<<sum[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    long long res = INF;
    for(int k = 2;k<max(n,m);k++){
        long long ans = 0;
        for(int i = k ;i<n+k;i+=k){
            for(int j = k ;j<m+k;j+=k){
                ans += min(a(i-k,j-k,i,j),k*k-a(i-k,j-k,i,j));
            }
        }
        res = min(res,ans);
    }
    cout<<res;
    return 0;
}