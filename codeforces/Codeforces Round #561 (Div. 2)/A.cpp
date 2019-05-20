#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

string a[105];

map<char,int> ma;

long long c(long long a){
    long long res = 0;
    a *= (a-1);
    a/=2;
    return a;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;

    long long res = 0;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        ma[a[i][0]]++;
    }
    for(auto it = ma.begin();it != ma.end();it++){
        res += c(it->second/2);
        if(it->second % 2 == 0){
            res += c(it->second/2);
        }else{
            res += c(it->second/2 + 1);
        }
    }
    cout<<res;
    return 0;
}