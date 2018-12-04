#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int i = n/2;
    int j = i;
    int flag = 1;
    int num = 1;
    int a[n][n];
    a[i][j] = 1;
    int count = 1;
    //·ÅÈë¾ØÕó
    while(1){
        if(flag == 1){
            for(int k = 0; k < count;k++){
                if(i == n-1 && j == n){
                    break;
                }
                j++;
                a[i][j] = ++num;
            }
            if(i == n-1 && j == n){
                break;
            }
            flag = 2;
            continue;
        }
        if(flag == 2){
            for(int k = 0; k < count;k++){
                i--;
                a[i][j] = ++num;
            }
            flag = 3;
            count++;
            continue;
        }
        if(flag == 3){
            for(int k = 0; k < count;k++){
                j--;
                a[i][j] = ++num;
            }
            flag = 4;
            continue;
        }
        if(flag == 4){
            for(int k = 0; k < count;k++){
                i++;
                a[i][j] = ++num;
            }
            flag = 1;
            count++;
            continue;
        }
    }
    for(i = 0; i<n;i++){
        for(j = 0; j<n;j++){
            printf("%d",a[i][j]);
            if(j != n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    int sum = 0;
    i = 0;
    j = 0;
    while(1){
        sum += a[i][j];
        i++;
        j++;
        if(i == n){
            break;
        }
    }
    i = 0;
    j = n-1;
    while(1){
        sum += a[i][j];
        i++;
        j--;
        if(i == n){
            break;
        }
    }
    printf("%d",sum-1);
    system("pause");
    return 0;
}