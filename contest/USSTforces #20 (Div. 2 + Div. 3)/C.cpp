#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

map<int,int> ma;
long long c[1000005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    string s,t;
    cin>>s>>t;
    int start = 0;
    while(start < s.length()){
        start = s.find(t,start);
        if(start == string::npos){
            break;
        }
        ma[start]++;
        start++;
    }
    int in = 1;
    memset(c,0,sizeof(c));
    for(auto it:ma){
        while(in < it.first+1){
            c[in] = c[in-1];
            in++;
        }
        c[in] = c[in-1]+1;
        in++;
    }
    while(in <= s.length()){
        c[in] = c[in-1];
        in++;
    }
    for(int i = 0; i< q;i++){
        int l,r;
        cin>>l>>r;
        if(r-(long long)t.length()+1 < l-1 || r-(long long)t.length()+1 < 0 || l-1 < 0 ){
            cout<<0<<endl;
            continue;
        }
        long long ans = c[r-(long long)t.length()+1]-c[l-1];
        if(ans < 0){
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}