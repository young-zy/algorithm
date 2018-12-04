#include<bits/stdc++.h>

using namespace std;

int main(){
    double input;
    scanf("%lf",&input);
    if(input<0 && input!=-3){
        
    }else if(input >=0 && input<10 && input !=2 &&input !=3 ){
        input++;
    }else{
        input = sin(3*input);
    }
    printf("%.6lf",input);
    return 0;
}