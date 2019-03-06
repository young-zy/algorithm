#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[6];
    int b[10000];
    int count = 0;
    memset(b,0,sizeof(b));
    for(int i =0 ;i<6;i++){
        scanf("%d",&a[i]);
    }
    for(int i =0 ;i<=a[0];i++){
        for(int j =0 ;j<=a[1];j++){
            for(int k = 0; k<= a[2];k++){
                for(int l = 0; l<=a[3];l++ ){
                    for(int m = 0; m<=a[4];m++){
                        for(int n = 0; n<=a[5];n++){
                            b[i + 2 * j + 3*k + 5*l +10*m +n*20]++;
                        }
                    }
                    
                }
            }
        }
    }
    for(int i =1 ;i <10000;i++){
        if(b[i]!= 0){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}