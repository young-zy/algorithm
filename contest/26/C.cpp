#include<bits/stdc++.h>

using namespace std;

long long a[100010];
long long q[100010][3];
long long ans[100010];
long long result[100010];

int main(){
    ans[0] = 0;
    int n,q;
    scanf("%d %d",&n,&q);
    for(int  i =1;i<=n;i++){
        scanf("%lld",&a[i]);
        ans[i] = ans[i-1]^a[i];
    }
    for(int i = 0 ;i < q;i++){
        long long l,r;
        long long x;
        scanf("%lld %lld",&l,&r);
        scanf("%lld",&x);
        ans[l] = ans[l]^x;
        ans[r] = ans[r]^x;
    }
    result[0] = 0;
    for(int i = 1; i<=n;i++){
        result[i] = ans[i]^ans[i-1];
    }
    for(int i = 1; i<=n;i++){
        printf("%d ",result[i]);
    }
    return 0;
}