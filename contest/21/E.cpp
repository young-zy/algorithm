#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a[31][2];
    a[1][0] = 2;
    a[1][1] = 1;
    for(int i = 2 ;i<30;i++){
        a[i][0] = pow(2,i);
        a[i][1] = 2*a[i-1][1]+1;
    }
    long long n;
    scanf("%lld",&n);
    int count = 0;
    if(n % 2 != 0){
        n--;
    }
    while(n > 0){
        for(int i =1 ; i<30;i++){
            if(n == 2){
                count++;
                n-=2;
                break;
            }else{
                if(n - a[i+1][0] < 0){
                    count += a[i][1];
                    n -= a[i][0];
                    break;
                }else{
                    continue;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}