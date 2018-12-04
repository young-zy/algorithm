#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int a[n*k][m];
    memset(a,0,sizeof(a));
    int l = 1;
    int count = 0;
    int result = 0;
    for(int i = 0 ; i< n*k;i++){
        for(int j = 0; j< m ;j++){
            if(l == n+1){
                l = 1;
                count++;
                if(n < m){
                    break;
                }
                
            }
            if(count == k){
                break;
            }
            a[i][j] = l;
            l++;
        }
        if(count == k){
            result = i;
            break;
        }
    }
    if(a[result][0] == 0){
        result--;
    }
    printf("%d",result+1);
   
    return 0;
}