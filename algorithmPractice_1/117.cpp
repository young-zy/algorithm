#include<bits/stdc++.h>

using namespace std;

int main(){
    string str,a;
    getline(cin,a);
    while(a != "end"){
        if(str != ""){
            str += "\n";
        }
        str+=a;
        getline(cin,a);
    }
    string b,c;
    getline(cin,b);
    getline(cin,c);
    str = str.replace(str.find(b),b.length(),c);
    cout<<str;
    return 0;
}