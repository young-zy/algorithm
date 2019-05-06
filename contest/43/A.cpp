#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    long n;
    cin>>n;
    string s;
    cin>>s;
    long long res = 0;
    for(int i = 0; i< n ; i++){
        if((s[i] - '0') & 1 ){
            res += i+1;
        }
    }
    cout<<res;
    return 0;
}