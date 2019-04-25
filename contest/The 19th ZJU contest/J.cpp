#include<bits/stdc++.h>

using namespace std;

int main(){
    long t;
    cin>>t;
    for(long te = 0; te< t;te++){
        unsigned long long n;
        scanf("%llu",&n);
        if(n % 2 == 0){
            printf("4 %llu\n",(unsigned long long)4+n);
        }else{
            printf("9 %llu\n",(unsigned long long)9+n);
        }
    }
    return 0;
}