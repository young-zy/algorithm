#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int count = 0;
    for(int i = 1;i <= 100 && count < n;i++){
        for(int j = 1;j <= 100 && count < n;j++){
            for(int k = 0;k <= 100 && count < n;k++){
                if(i*5+j*2+k == 150 && i+j+k == 100){
                    if(count != 0){
                        printf("\n");
                    }
                    printf("%d %d %d",i,j,k);
                    count++;
                }
            }
        }
    }
    return 0;
}