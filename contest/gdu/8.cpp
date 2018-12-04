#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0;i<t;i++){
        int n;
        scanf("%d",&n);
        while(n !=1){
            if(n % 2 == 0){
                printf("%d/2=%d\n",n,n/2);
                n /= 2;
            }else{
                printf("%d*3+1=%d\n",n,n*3+1);
                n*=3;
                n++;
            }
        }
        if(i != t){
            printf("\n");
        }
    }
    return 0;
}