#include<bits/stdc++.h>

using namespace std;

int main(){
    int m,n;
    while(1){
        scanf("%d %d",&n,&m);
        if(m == 0, n == 0){
            break;
        }
        int a[n][m][2];
        memset(a,0,sizeof(a));
        for(int i = 0; i <n;i++){
            for(int j = 0; j<m;j++){
                scanf("%d",&a[i][j][0]);
            }
        }
        for(int i = 0; i <n;i++){
            for(int j = 0; j<m;j++){
                if(i-1>=0){
                    if(a[i-1][j][0]>0 && a[i][j][0]<0 || a[i-1][j][0]<0 && a[i][j][0]>0){
                        a[i][j][1]+=fabs(a[i-1][j][0]);
                    }else{
                        a[i][j][1]-=fabs(a[i-1][j][0]);
                    }
                }
                if(i+1<n){
                    if(a[i+1][j][0]>0 && a[i][j][0]<0 || a[i+1][j][0]<0 && a[i][j][0]>0){
                        a[i][j][1]+=fabs(a[i+1][j][0]);
                    }else{
                        a[i][j][1]-=fabs(a[i+1][j][0]);
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1][0]>0 && a[i][j][0]<0 || a[i][j-1][0]<0 && a[i][j][0]>0){
                        a[i][j][1]+=fabs(a[i][j-1][0]);
                    }else{
                        a[i][j][1]-=fabs(a[i][j-1][0]);
                    }
                }
                if(j+1<m){
                    if(a[i][j+1][0]>0 && a[i][j][0]<0 || a[i][j+1][0]<0 && a[i][j][0]>0){
                        a[i][j][1]+=fabs(a[i][j+1][0]);
                    }else{
                        a[i][j][1]-=fabs(a[i][j+1][0]);
                    }
                }
            }
        }
        int maxi = 0;
        int maxj = 0;
        int maxdata = a[0][0][1];
        for(int i = 0; i <n;i++){
            for(int j = 0; j<m;j++){
                if(a[i][j][1]>maxdata){
                    maxdata = a[i][j][1];
                    maxi = i;
                    maxj = j;
                }
            }
        }
        printf("%d %d %d\n",maxi+1,maxj+1,maxdata);
    }
    return 0;
}