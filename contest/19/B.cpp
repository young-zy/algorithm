#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

long fast_exp(long a, long b){
    long res = 1;
    while(b){
        if(b & 1){
            res = res * a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long a,b;
    long count = 0;
    while(cin>>a>>b){
        long long ans=0;
        
        cout<<"Case "<<++count<<": "<<ans<<endl;
    }
    return 0;
}