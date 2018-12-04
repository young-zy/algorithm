#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int a[n][m];
    memset(a,-1,sizeof(a));
    if(p>m && p>n){
        printf("No");
        return 0;
    }else if(n*m % p != 0){
        printf("No");
        return 0;
    }else{
        int count = 1;
        int c = 0;
        for(int i = 0;i< n;i++){
            int tempm = m;
            while(1){
                if(tempm>=p){
                    for(int j = 0;j< p;j++){
                        a[i][j +m - tempm] = count;
                    }
                    tempm-=p;
                    count++;
                }else{
                    c = tempm;
                    break;
                }
            }
        }
        for(int j = m-c;j<m;j++){
            int tempn = n;
            while(1){
                if(tempn>=p && a[n-tempn][j] == -1){
                    for(int i = 0;i<p;i++){
                        a[i + n-tempn][j] = count;
                    }
                    tempn -= p;
                    count ++;
                }else{
                    break;
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == -1){
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",a[i][j]);
            if(j !=m-1){
                printf(" ");
            }
        }
        if(i != n-1){
            printf("\n");
        }
    }
    system("pause");
    return 0;
}