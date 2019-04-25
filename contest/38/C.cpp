#include<bits/stdc++.h>

using namespace std;

unsigned long long a[100005];

int main(){
    unsigned long long sum = 0;
    long long count =0;
    unsigned long long m;
    long n;
    cin>>m>>n;
    for(long i = 0; i< n ; i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    a[n] = m;
    if(a[0] != 1){
        cout<<-1;
        return 0;
    }
    for(int i = 0; i< n; i++){
        unsigned long long b;
        if(a[i+1] >= m ){
            b = (m - sum)/a[i];
            if(b * a[i] + sum < m){
                b++;
            }
            count += b;
            break;
        }
        b = (a[i+1]-sum -1)/a[i];
        if(sum + b * a[i] < a[i+1] - 1){
            b++;
        }
        count += b;
        sum +=b* a[i];
    }
    cout<<count;
    return 0;
}