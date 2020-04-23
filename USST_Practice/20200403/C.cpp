#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    if(s[s.length()-1] == 'r'){
        if(s[s.length()-2] == 'e'){
            s= s.substr(0,s.length()-2);
        }
    }else if(s[s.length()-1] == 'y'){
        if(s[s.length()-2] == 'l'){
            s= s.substr(0,s.length()-2);
        }
    }else if(s[s.length()-1] == 'g'){
        if(s[s.length()-2] == 'n'){
            if(s[s.length()-3] == 'i'){
                s= s.substr(0,s.length()-3);
            }
        }
    }
    cout<<s;
    return 0;
}