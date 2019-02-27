#include<bits/stdc++.h>

using namespace std;

int a[1000005];
int b[1000005];

int main(){
    long m,n;
    scanf("%ld %ld",&m,&n);
    b[0] = 0;
    for(long i =0; i<n; i++){
        scanf("%d",&a[i]);
        b[i+1] = b[i]+a[i];
    }
    sort(a,a+n);
    long result;
    
    return 0;
}