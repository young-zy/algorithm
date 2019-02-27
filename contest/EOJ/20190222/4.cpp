#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i<t;i++){
        unsigned long long l,r;
        unsigned long long count = 0;
        scanf("%llu %llu",&l,&r);
        int k,m;
        scanf("%d %d",&k,&m);
        for(unsigned long long j = l;j<=r;j++){
            int flag = 1;
            unsigned long long num = j;
            for(int i1 = 0; i1<=m; i1++){
                if(num % k !=0){
                    if(i1==m){
                    }else{
                        flag = 0;
                        break;
                    }
                }else{
                    if(i1 == m){
                        flag = 0;
                        break;
                    }
                    num/=k;
                    if(num == 0 && i1 <m -1){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 1){
                count++;
            }
        }
        printf("%llu\n",count);
    }
    return 0;
}