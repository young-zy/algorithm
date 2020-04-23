#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,n;
    cin>>l>>n;
    int maxnum = 0,minnum = 0;
    for(int i = 0; i<n ; i++){
        int b;
        cin>>b;
        maxnum = max(maxnum, max(l-b+1,b));
        minnum = max(minnum, min(l-b+1,b));
    }
    cout<<minnum<<" "<<maxnum;
    return 0;
}