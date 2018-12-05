#include<bits/stdc++.h>

using namespace std;

int main(){
    double input;
    scanf("%lf",&input);
    double temp = input;
    if(input <0){
        input =fabs(input+1);
    }else if(input >=0 &&input <=5){
        input =2*input +1;
    }else{
        input = sin(input)+5;
    }
    printf("x=%.2lf,y=%.2lf",temp,input);
    return 0;
}