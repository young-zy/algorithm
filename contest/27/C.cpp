#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    double a[n];
    for(int i = 0;i<n ;i++){
        scanf("%lf",&a[i]);
    }
    sort(a,a+n);
    if(k <= n){
        printf("%lf",a[n-k]);
    }else{

    }
    return 0;
}