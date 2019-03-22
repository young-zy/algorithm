#include<bits/stdc++.h>

using namespace std;

long quickmod(long a, long b, long c);

int main(){
    unsigned long long i ;
    while(~scanf("%d",&i)){
        
    }
    return 0;
}

long quickmod(long a, long b, long c){
    long ans = 1;
    a %= c;
    while(b != 0){
        if(b&1){
            ans=(ans*a)%c;
        }
       b>>1;
        a = (a * a) % c;
    }
    return ans;
}