#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[n];
    for(int i = n-1; i >= 0; i--){
        if(a[i] + i > n){
            b[i] = 1;
            continue;
        }else{
            int min = n+1;
            for(int j = 1; j <= a[i];j++){
                if(b[i+j] + 1 < min){
                     min = b[i+j] + 1;
                }
            }
            b[i] = min;
        }
        
    }
    if(b[0] == n+1){
        b[0] = -1;
    }
    printf("%d",b[0]);
    system("pause");
    return 0;
}