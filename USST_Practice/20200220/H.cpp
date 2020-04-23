#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int n,a;
    for(int ti = 0; ti < t; ti++){
        scanf("%d %d",&n, &a);
        int b,c;
        if(n > 2){
            b = -1;
            c = -1;
        }else if( n == 1 ){
            b = 1;
            c = a+1;
        }else if(n == 0){
            b = -1;
            c = -1;
        }else{
            int n = a/2;
            if( a % 2 ){
                b = a*n+n;
                c = b+1;
            }else{
                b = (a*n)/2-1;
                c = b+2;
            }
        }
        printf("%d %d\n",b,c);
    }
    return 0;
}