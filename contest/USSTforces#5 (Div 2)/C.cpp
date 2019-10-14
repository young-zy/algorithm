#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[105];

long long _round(long double a){
    long long ans = 0;
    ans = (long long)(a+0.5);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    long double sum = 0;
    for(long long i = 0; i<n ; i++){
        cin>>a[i];
        sum += a[i];
    }
    long double target = k-0.5;
    long double ans = (target*n-sum)*2;
    if(ans < 0){
        ans = 0;
    }
    cout<<_round(ans);
    // for(int i = 0; i <n ; i++){

    // }
    return 0;
}