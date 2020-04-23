#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[105];
int b[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ; te++){
        int n,m;
        cin>>n>>m;
        for(int i = 0; i<n ; i++){
            cin>>a[i];
        }
        for(int i = 0; i<m ; i++){
            cin>>b[i];
        }
        if(n > m ){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}