#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    char c;
    scanf("%d %d %c",&a,&b,&c);
    double base;
    double result;
    double discount;
    if(b == 90){
        base = 6.95;
    }else if( b == 93 ){
        base = 7.44;
    }else{
        base = 7.93;
    }
    if(c == 'm'){
        discount = 0.95;
    }else{
        discount = 0.97;
    }
    result = base * a *discount;
    printf("%.2lf",result);
    return 0;
}