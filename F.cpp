#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n;
    cin>>n;
    int count = 0;
    while(n){
        unsigned long long temp = n;
        unsigned long long num = 0;
        while(temp){
            num = max(num , temp % 10);
            temp /= 10;
        }
        n -= num;
        count++;
    }
    cout<<count;
    return 0;
}