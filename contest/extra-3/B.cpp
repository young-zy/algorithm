#include<bits/stdc++.h>
#define endl "\n"

using namespace std;



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    long n;
    cin>>n;
    unsigned long long ans = 0;
    while(n){
        if(n & 1){
            ans += (1 + n) * (n/2+1)/2;
        }else{
            ans += n*(n/2)/2; 
        }
        n/=2;
    }
    cout<<ans;
    return 0;
}