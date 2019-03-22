#include<bits/stdc++.h>

using namespace std;

long quickmod(long a, long b,long c);

int main(){
    long n,m,k,x;
	cin>>n>>m>>k>>x;
	unsigned long long times = 1;
	long time = 0;
    long start = 0;
    while(1){
        start += m;
        if(start >= n){
            start -= n;
        }
        time++;
        if(start == 0){
            break;
        }
    }
    long left = quickmod(10,k,time);
    while(left){
        x+=m;
        if(x>=n){
            x-=n;
        }
        left--;
    }
    cout<<x;
    return 0;
}

long quickmod(long a, long b,long c){
    long res = 1;
    a %= c;
    while(b){
        if(b & 1){
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b>>=1;
    }
    return res;
}