#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(long i = 0; i< a.length();i++){
        for(long j = 0; j< b.length();j++){
            if(a[i] == b[j]){
                a.erase(i,1);
                i--;
            }
        }
    }
    cout<<a;
    return 0;
}