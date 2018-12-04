#include<bits/stdc++.h>

using namespace std;

long n,I,h,r;

int main(){
    long c[10000];
    scanf("%ld %ld %ld %ld",&n,&I,&h,&r);
    for(int i = 0; i< n ;i++){
        c[i] = h;
    }
    for(int i = 0; i<r;i++){
        long a,b;
        scanf("%ld %ld",&a,&b);
        if(c[a-1]>c[b-1]){
            c[a-1] = c[b-1];
        }
        if(b>a){
            for(long j = a;j<b-1;j++){
                c[j] = c[j]-1;
            }
        }else{
            for(long j = a-2;j>b-1;j--){
                c[j] = c[j]-1;
            }
        }
    }
    for(int i = 0; i< n;i++){
        printf("%ld\n",c[i]);
    }
    return 0;
}