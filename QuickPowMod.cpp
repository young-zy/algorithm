#include<bits/stdc++.h>

using namespace std;

int main(){
    long a,b,c;  // a ^ b mod c
    cin>>a>>b>>c;
    long ans = 1;
    a %= c;
    while(b){
        if(b & 1){
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a*a) % c;

    }
    cout<<ans;
    return 0;
}