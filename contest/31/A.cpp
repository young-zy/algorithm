#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n][10][10];
    for(int i= 0; i<n;i++){
        scanf("%d",&a[i]);
    }
    int num = 1;
    int minus = 0;
    for(int i =0 ;i <n ;i++){
        for(int j =0 ;j<a[i];j++){
            for(int k =0 ;k<10;k++){
                if(k == 0){
                    if(j == 0){
                        b[i][j][k] = i+1;
                    }else{
                        b[i][j][k] = b[i][j-1][9] + n -j;
                    }
                }else{
                    b[i][j][k] = b[i][j][k-1]+n-j;
                }
            }
        }
    }
        for(int i =0; i<n ;i++){
            printf("#%d\n",i+1);
            for(int j = 0; j<a[i];j++){
                for(int k = 0; k< 10;k++){
                    printf("%d",b[i][j][k]);
                    if(k != 9){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

    return 0;
}