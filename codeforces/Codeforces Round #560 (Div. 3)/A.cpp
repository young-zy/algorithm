#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    long long count = 0;
    for(int i = s.length()-1; i>s.length() - y-1; i--){
        if(s[i] == '1'){
            count++;
        }
    }
    if(s[s.length() - y - 1] == '0'){
        count++;
    }
    for(int i = s.length() - y - 2;i>s.length() - x-1;i--){
        if(s[i] == '1'){
            count++;
        }
    }
    cout<<count;
    return 0;
}