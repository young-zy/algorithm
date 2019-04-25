#include<bits/stdc++.h>

using namespace std;

string reverseStr(string a){
    for(long i = 0; i< a.length()/2;i++){
        char temp = a[i];
        a[i] = a[a.length()-i-1];
        a[a.length()-i-1] = temp;
    }
    return a;
}

int main(){
    string s;
    string t;
    cin>>s;
    while(s.size()){
        int move = 0;
        while(s[0+move] == s[s.length() - move-1] && 0+move < s.length() - move-1){
            move++;
        }
        if(s[0+move] < s[s.length() - move-1]){
            t.append(reverseStr(s.substr(s.length() - move-1)));
            s.erase(s.length() - move-1);
        }else{
            t.append(s.substr(0,move+1));
            s.erase(0,move+1);
        }
    }
    cout<<t;
    return 0;
}

