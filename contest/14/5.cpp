#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    long result = 0;
    scanf("%ld",&n);
    for(int i = 1;i<=n;i++){
        if(i % 2 == 1){
            result += i;
        }else{
            long temp = i;
            while(temp % 2 == 0){
                temp /=2;
            }
            result += temp;
        }
    }
    printf("%ld",result);
    return 0;
}