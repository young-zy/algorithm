#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i = 0; i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        if(n-m < 0){
            cout<<0<<endl;
        }else{
            cout<<min(n-m,k+1)<<endl;
        }
    }
    return 0;
}