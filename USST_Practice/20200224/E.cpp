#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    for(int te = 0; te<t; te++){
        cin>>n;
        cout<<1;
        for(int i = 0; i< n-1;i++){
            cout<<0;
        }
        cout<<endl;
    }
    return 0;
}