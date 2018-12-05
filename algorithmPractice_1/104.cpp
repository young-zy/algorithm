#include<bits/stdc++.h>

using namespace std;

int main(){
    int a;
    scanf("%d",&a);
    double b=0;
    if(a>4500){
        b+=(a-1600)*0.2;
    }else if(a>3500){
        b+=(a-1600)*0.15;
    }else if(a>2500){
        b+=(a-1600)*0.1;
    }else if(a>1600){
        b+=(a-1600)*0.05;
    }
    printf("%.2lf",b);
    return 0;
}