#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const long long mod = 998244353;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, int> ma;
    long long ans = 0;
    long long a = 0,b = 0;
    for(int i = 0; i<n ; i++){
        ma[s[i]]++;
        if(ma.size() >1){
            break;
        }else{
            a++;
        }
    }
    ma.clear();
    for(int i = n-1; i>=0 ; i--){
        ma[s[i]]++;
        if(ma.size() >1){
            break;
        }else{
            b++;
        }
    }
    if(s[0] == s[n-1]){
        ans += (++a*++b)%mod;
        ans %=mod;
    }else{
        ans = (a+b+1);
    }
    ans %=mod;
    cout<<ans;
    return 0;
}