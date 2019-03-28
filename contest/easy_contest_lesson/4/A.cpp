#include<bits/stdc++.h>

using namespace std;

long long a[500005];
long long b[500005];
long long res[10000000];

int main(){
    long n;
    cin>>n;
    priority_queue<long long,vector<long long> , greater<long long> > pq;
    for(long  i = 0; i< n ; i++){
        scanf("%lld",&a[i]);
    }
    for(long i = 0; i< n ; i ++){
        scanf("%lld",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    for(long i = 0; i< 101 && i < n;i++){
        for(long j = 0 ; j< n ; j++){
            pq.push(a[i]+b[j]);
        }
    }
    long count = 0;
    while(count < n){
        cout<<pq.top()<<" ";
        pq.pop();
        count++;
    }
    return 0;
}