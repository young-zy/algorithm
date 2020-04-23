#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

long long a[100005];
long long sum[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    sum[0] = 0;
    long long l = -INF;
    long long r = 0;
    long long mid;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        l = max(l, a[i]);
        sum[i+1] = sum[i]+a[i];
    }
    r = sum[n];
    int res = INF;
    while(l < r){
        mid = (l+r) >> 1;
        long long temp = 0;
        long long count = 0;
        for(int i = 0; i<n; i++){
            if(temp + a[i] <= mid){
                temp += a[i];
            }else{
                temp = a[i];
                count++;
            }
        }
        count++;
        if(count <= m){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<r;
    return 0;
}