#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,r;
    cin>>n>>l>>r;
    long long base = 1;
    long long minnum = 0;
    int count = 0;
    for(int i = 0; i<l; i++){
        minnum += base;
        count++;
        base <<=1;
    }
    int temp = count;
    long long maxnum = minnum;
    for(int i = 0; i<n-temp && count < r;i++){
        maxnum += base;
        base <<= 1;
        count++;
    }
    if(count < n){
        maxnum += (n-count)*(base>>1);
    }
    minnum += n-temp;
    cout<<minnum<<" "<<maxnum;

    return 0;
}