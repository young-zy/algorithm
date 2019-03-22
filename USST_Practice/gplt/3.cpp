#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    map<char,int> m;
    for(int i =0 ;i < b.length();i++){
        if(!m[b[i]]){
            m[b[i]]++;
        }
    }
    for(int i =0 ; i< a.length();i++){
        if(m[a[i]]){
            a.erase(i,1);
            i--;
        }
    }
    cout<<a;
    return 0;
}