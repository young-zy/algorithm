#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,w;
    cin>>n>>w;
    long long maxnum = 0;
    long long minnum = w;
    long long lastmin = 0;
    long long lastmax = w;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        lastmin += a[i];
        lastmax += a[i];
        minnum = min(minnum,w-(lastmax-w));
        maxnum = max(maxnum,0-lastmin);
    }
    if(minnum < maxnum){
        cout<<0;
    }else{
        cout<<minnum-maxnum+1;    
    }
    return 0;
}