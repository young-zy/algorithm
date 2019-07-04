#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin>>n>>m;
    long l = max(m,n);
    long s = min(m,n);
    long t = (s+1)/3*(l+1)/2;
    if(s % 3 == 1){
        t += (l+1)/3;
    }
    cout<<t;
    return 0;
}