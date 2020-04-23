#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    string t;
    cin>>t;
    int i = 0, j = t.length()-1;
    int pre[t.length()];
    memset(pre,0,sizeof(pre));
    for(int i = 1; i<t.length(); i++){
        int j = pre[i-1];
        while(j > 0 && t[j] != t[i]){
            j = pre[j-1];
        }
        if(t[i] == t[j]){
            j++;
        }
        pre[i] = j;
    }
    for(int i =0 ; i< k-1;i++){
        cout<<t.substr(0,t.length()-pre[t.length()-1]);
    }
    cout<<t;
    return 0;
}