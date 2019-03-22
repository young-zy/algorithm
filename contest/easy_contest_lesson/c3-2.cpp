#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    long long leng = 0;
    long long res = 0;
    for(long i = 0; i < a.length();i++){
        if(a[i] == 'O'){
            leng++;
            res += leng;
        }else{
            leng = 0;
        }
    }
    cout<< res;
    return 0;
}