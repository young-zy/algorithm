#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;

long long a[5000][5000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 0;i<3000;i++){
        a[i][i] = 1;
        a[i][0] = 1;
    }
    for(int i = 2; i< 3000;i++){
        for(int j = 1; j<= i;j++){
            a[i][j] = a[i-1][j]+a[i-1][j-1];
            a[i][j] %= MOD;
        }
    }
    for(int te = 0; te< t; te++){
        int n,m;
        cin>>n>>m;
        cout<<a[m+n-2][n-1]<<endl;
    }
    return 0;
}