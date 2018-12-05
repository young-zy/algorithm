#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,n;
    int sum = 0;
    scanf("%d %d",&a,&n);
    for(int i = 1;i<=n;i++){
        sum += i*(a*pow(10,n-i));
    }
    printf("s = %d",sum);
    return 0;
}