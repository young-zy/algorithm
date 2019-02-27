#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    map<long long,long long> ma;
    for(int i = 1; i<=n;i++){
        ma[i]++;
    }
    for(int i = m; i>1;i--){
        ma[i]--;
    }
    for(int i = n-m; i>1;i--){
        ma[i]--;
    }
    unsigned long long result = 1;
    for(map<int,int>::reverse_iterator rit = ma.rbegin();rit != ma.rend();rit++){
        if(rit->second != 0){
            result *= pow(rit->first,rit->second);
        }
    }
    unsigned long long count = 0;
    int flag = 0;
    for(unsigned long long i = 1;i<=sqrt(result);i++){
        if(result % i == 0){
            count++;
        }
        if(i == sqrt(result)){
            flag = 1;
        }
    }
    count*=2;
    if(flag == 1){
        count--;
    }
    printf("%llu",count);
    return 0;
}