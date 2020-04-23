#include<iostream>
#define endl "\n"

const int INF=0x3f3f3f3f;
const int MOD=1000;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    int base = a;
    while(--b){
        a *= base;
        a %= MOD;
    }
    cout<<a;
    return 0;
}