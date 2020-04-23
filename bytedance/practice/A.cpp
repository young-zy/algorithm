#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        string s;
        cin>>s;
        for(int i = 0; i<s.length()-3;){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                s.erase(i+2,1);
                continue;
            }
            if(s[i] == s[i+1] && s[i+2] == s[i+3]){
                s.erase(i+3,1);
                continue;
            }
            i++;
        }
        if(s.length() >= 3 && s[s.length()-2] == s[s.length()-1] && s[s.length()-3] == s[s.length()-1]){
            s.erase(s.length()-1);
        }
        cout<<s<<endl;
    }
    return 0;
}