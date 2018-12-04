#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[2*n-1];
    for(int i = 0; i<2*n-1;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+2*n-1);
    int count = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i<2*n-1;i++){
        if(a[i]>=0){
            break;
        }else{
            count++;
        }
    }
    int time = count/n;
    for(int i = 0;i<time;i++){
        for(int j = 0;j<n;j++){
            a[i*n+j] = -a[i*n+j];
        }
    }
    for(int i = 0; i< 2*n-1;i++){
        sum1 += a[i];
    }
    for(int i = time*n;i<time*n+n;i++){
        a[i] = -a[i];
    }
    for(int i = 0; i< 2*n-1;i++){
        sum2 += a[i];
    }
    if((time+1)*n> 2*n-1){
        sum2 = sum1;
    }
    printf("%d",max(sum1,sum2));
    system("pause");
    return 0;
}