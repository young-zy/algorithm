#include<bits/stdc++.h>

using namespace std;

long a[300005];
long b[300005];

int main(){
    long n;
    cin>>n;
    for(long i = 0; i< n;i++){
        cin>>a[i];
        if(i != 0){
            b[i] = fabs(a[i]- a[i-1]);
        }
    }
    long res = 0;
    long maxres = 0;
    
    return 0;
}

long quickmod(long a, long b, long c){
    long ans = 1;
    a %= c;
    while(b != 0){
        if(b&1){
            ans=(ans*a)%c;
        }
        b>>=1;
        a = (a * a) % c;
    }
    return ans;
}