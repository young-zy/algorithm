#include<iostream>
#include<cstdio>
#include<string.h>

#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;


const int MAXN=10000;
int prime[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    memset(prime,111,sizeof(prime));
    prime[1] = 0;
    for(int i = 2; i<=10000; i++){
        for(int j = i*2; j<=10000; j += i){
            prime[j] = 0;
        }
    }
    while(1){
        scanf("%d",&n);
        if(n == 0){
            return 0;
        }
        int sum = 0;
        int cou = 0;
        for(int i = 2; i<=n;i++){
            sum = 0;
            if(prime[i]){
                for(int j = i; j<=n;j++){
                    if(prime[j]){
                        sum += j;
                        if(sum == n){
                            cou++;
                        }else if(sum > n){
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",cou);
    }
    return 0;
}