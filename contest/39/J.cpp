#include<bits/stdc++.h>

using namespace std;

int n;
long a[300005];
long b[300005];
long flag[300005];


int main(){
    memset(b,-1,sizeof(b));
    long n;
    scanf("%ld",&n);
    for(long i = 0; i< n ; i++){
        scanf("%ld",&a[i]);
    }   
    long depth = 0;
    flag[0] = 1;
    for(long i =1; i< n ; i++){
        scanf("%ld",&b[i]);
        if(b[i] > depth){
            depth = b[i];
        }
        if(flag[b[i]] == 0){
            flag[b[i]] = 1;
        }
    }
    b[0] = -1;
    
    
    return 0;
}