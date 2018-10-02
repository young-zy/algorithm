#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(b == 0){
        printf("%d/0=Error",a);
        return 0;
    }
    double result = (double)a/b;
    printf("%d/",a);
    if(b<0){
        printf("(%d)",b);
    }else{
        printf("%d",b);
    }
    if(fabs(result) < DBL_EPSILON){
        result = fabs(result);
    }
    printf("=%.2lf",result);
    return 0;
}