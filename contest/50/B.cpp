#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<string,int> ma;
    for(int i = 0; i<n ; i++){
        string temp;
        cin>>temp;
        ma[temp]++;
    }
    auto maxit = ma.begin();
    for(auto it = ma.begin();it != ma.end();it++){
        if(it->second > maxit->second){
            maxit = it;
        }
    }
    cout<<maxit->first;
    return 0;
}