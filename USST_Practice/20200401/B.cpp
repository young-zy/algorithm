#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,k;
    cin>>k>>s;
    int i = 0;
    int j = 0; 
    while(i < s.length()){
        if(s[i] >='a' && s[i] <= 'z'){
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] -= k[j]-'a';
            }else{
                s[i] -= k[j] - 'A';
            }
            if(s[i] < 'a'){
                s[i] += 26;
            }
        }else{
            if(k[j] >= 'a' && k[j] <= 'z'){
                s[i] -= k[j]-'a';
            }else{
                s[i] -= k[j] - 'A';
            }
            if(s[i] < 'A'){
                s[i] += 26;
            }
        }
        i++;
        j++;
        if(j >= k.length() ){
            j = 0;
        }
    }
    cout<<s;
    return 0;
}