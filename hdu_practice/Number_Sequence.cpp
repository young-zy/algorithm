#include<bits/stdc++.h>

using namespace std;

int f(int n,int a,int b){
    if(n ==1 || n == 2){
        return 1;
    }else{
        return (a*f(n-1,a,b) +b*f(n-2,a,b)) % 7;
    }
}

int main(){
    int a,b,n;
    while(1){
        scanf("%d %d %d",&a,&b,&n);
        if(a == 0 && b==0 & n==0){
            break;
        }
        int result = f(n,a,b);
        printf("%d\n",result);
    }
    return 0;
}