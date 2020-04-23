#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a = 0, b = 1;
    while(n--){
        int newb = a+1;
        int newa = a+b;
        b = newb;
        a = newa;
    }
    cout<<a<<" "<<a+b;
    return 0;
}