#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    int l,r;
    bool operator < (node no) const{
        if(l == no.l){
            return r<no.r;
        }
        return l < no.l;
    }
};

node no[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int l,r;
    for(int i =0; i<n ; i++){
        cin>>no[i].l>>no[i].r;
    }
    
    return 0;
}