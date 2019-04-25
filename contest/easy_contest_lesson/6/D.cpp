#include<bits/stdc++.h>

using namespace std;

long a[100005];

int main(){
    long n;
    cin>>n;
    for(long i = 0; i<n ; i++){
        scanf("%ld",&a[i]);
    }
    long m;
    cin>>m;
    sort(a,a+n);
    for(long i = 0; i<= n/2 ; i++){
        for(long j = n-1 ; j> i;j--){
            if(a[i] + a[j] == m){
                cout<<a[i]<<" "<<a[j];
                return 0;
            }else if(a[i] + a[j] < m){
                break;
            }
        }
    }
    cout<<"No";
    return 0;
}