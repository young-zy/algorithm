#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int rec(int a,int b){
    if(a == 1){
        return 1;
    }
    if(b == 1){
        return 0;
    }
    if(a % b == 0){
        return rec(a/b, b) + rec(a, b-1);
    }
    return rec(a, b-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<rec(n,n);
    return 0;
}