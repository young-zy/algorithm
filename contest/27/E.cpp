#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long b,s;
    s = 0;
    scanf("%d %lld",&n,&b);
    int hi[n];
    for(int i =0 ; i<n;i++){
        scanf("%d",&hi[i]);
    }
    sort(hi,hi+n);
    int i = n-1;
    int count = 0;
    while(s<b){
        s+=hi[i];
        count++;
        i--;
    }
    printf("%d",count);
    return 0;
}