#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    int k;
    cin>>n>>k;
    while(k--){
        for(int i = 0 ; i<=n.length()-1 ; i++){
            if(n[i] > n[i+1] || i == n.length()-1){
                n.erase(i,1);
                break;
            }
        }
    }
    cout<<n;
    return 0;
}