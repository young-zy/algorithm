#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    if(min(m,k) < n){
        cout<<"NO";
    }else{
        cout<<"YES";
    }
    return 0;
}