#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0 ; te < t ; te++){
        int n,m,p;
        cin>>n>>m>>p;
        for(int i = 0; i<m ; i++){
            cin>>a[i][0]>>a[i][1];
        }
    }
    return 0;
}