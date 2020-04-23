#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    int a,b,v;
    bool operator < (node no) const{
        return v < no.v;
    }
};

node no[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b,v;

    for(int i = 0; i<m ; i++){
        cin>>a>>b>>v;
    }
    return 0;
}