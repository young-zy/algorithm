#include<bits/stdc++.h>

using namespace std;

long fish[200000][2];
long fisher[200000];

int main(){
    long n,m,l;
    scanf("%ld %ld %ld",&n,&m,&l);
    
    for(long i = 0;i < n;i++){
        scanf("%d %d",&fish[i][0],&fish[i][1]);
    }
    
    for(long i = 0; i< m;i++){
        scanf("%d",&fisher[i]);
    }
    for(long i = 0 ; i < m ; i++){
        long count = 0;
        for(long j = 0; j < n ; j++){
            if(l-fish[j][1]<0){
                continue;
            }
            long dis = fabs(fish[j][0]-fisher[i]);
            if(dis>l){
                continue;
            }
            dis += fish[j][1];
            if(dis>l){
                continue;
            }else{
                count++;
            }
        }
        printf("%ld\n",count);
    }
    return 0;
}