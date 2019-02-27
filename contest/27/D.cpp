#include<bits/stdc++.h>

using namespace std;


int main(){
    long n;
    scanf("%ld",&n);
    int count = 0;
    unsigned long long result = 1;
    if(n<=2){
        result = n;
    }else if(n %2 == 1){
        result = n*(n-1)*(n-2);
    }else{
        if(n%3 == 0){
            result = (n-1)*(n-2)*(n-3);
        }else{
            result = n*(n-1)*(n-3);
        }
    }
    printf("%llu",result);
    return 0;
}

