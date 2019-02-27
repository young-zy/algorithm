#include<bits/stdc++.h>

using namespace std;

unsigned long long a[100005],rest[100005],tag[100005];

int main(){
    int n,k;
    unsigned long long count = 0;
    memset(rest,0,sizeof(rest));
    memset(tag,0,sizeof(tag));
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n; i++){
        scanf("%llu",&a[i]);
    }
    a[0] %= k;
    rest[0] = a[0];
    for(int i =1;i<n; i++){
        rest[i] = (rest[i-1]+a[i]) % k;
    }

    for(int i =0; i<n; i++){
        count+= tag[rest[i]]++;
    }
    printf("%llu",count+tag[0]);
    return 0;
}