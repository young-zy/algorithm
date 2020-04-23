#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int maxn = 1;
    while(n){
        maxn = max(maxn, n % 10);
        n /= 10; 
    }
    cout<<maxn;
    return 0;
}