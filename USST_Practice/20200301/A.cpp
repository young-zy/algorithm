#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int k;
    while(cin>>n){
        int res = 1;
        k = 1;
        while(k){
            k = (k*10+1)%n;
            res++;
        }
        if(n == 1){
            res = 1;
        }
        cout<<res<<endl;
    }
    return 0;
}