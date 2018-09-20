#include<bits/stdc++.h>

using namespace std;

int main(){
    float x;
    float y;
    scanf("%f",&x);
    if(x-15 > DBL_EPSILON){
        y = 2.5*x-17.5;
    }else{
        y = 4*x/3;
    }
    printf("%.2f",y);
    return 0;
}