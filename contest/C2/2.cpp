#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    int count = 0;
    long res = 0;
    for(long i = 0; i<a.length();i++){
        if(a[i] == 'O'){
            count++;
            res+=count;
        }else{
            count = 0;
        }
    }
    cout<<res;
    return 0;
}