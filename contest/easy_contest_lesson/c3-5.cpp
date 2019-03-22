#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    string a;
    cin>>n;
    cin>>a;
    
    return 0;
}

long fastmod(long a, long b, long c){
    long result;
    a %= c;
    while(b){
        if(b & 1){
            result = (result * a) % c;
        }
        a = (a * a) %c;
        b>>=1;
    }
    return result;
}