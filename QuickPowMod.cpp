#include<bits/stdc++.h>

using namespace std;

long long quickpowmod(long long a,long long b,long long c){
    // a ^ b mod c
    long long ans = 1;
    a %= c;
    while(b){
        if(b & 1){
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a*a) % c;
    }
    return ans;
}