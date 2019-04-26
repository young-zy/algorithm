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
        if(a > b){
            for(int i = a-2;i>b-1;i--){
                c[i]--;
            }
        }else{
            for(int i = a;i<b-1;i++){
                c[i]--;
            }
        }
    }
    for(int i = 0; i< n;i++){
        printf("%ld\n",c[i]);
    }
    return 0;
}