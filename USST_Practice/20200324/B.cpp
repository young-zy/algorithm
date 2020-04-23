#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int m,n;

int res = 0;

int rec(int m, int n){
    if( m == 0 || n == 1){
        return 1;
    }
    if(n > m){
        return rec(m,m);
    }else{
        return rec(m, n-1) + rec(m-n, n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    cout<<rec(m, n);
    return 0;
}