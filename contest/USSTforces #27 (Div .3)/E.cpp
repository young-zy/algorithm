#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int index = 0;
    for(int i = 0; i<s.length();i++){
        if(s[i] == '.'){
            index = i;
            break;
        }
    }
    if(s[index-1] == '9'){
        cout<<"GOTO Vasilisa.";
        return 0;
    }else{
        if(s[index+1] >='5'){
            s[index-1]++;
        }
    }
    s.erase(index);
    cout<<s;
    return 0;
}