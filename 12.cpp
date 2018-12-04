#include<bits/stdc++.h>

using namespace std;

int main(){
    float money,year,rate;
    scanf("%f %f %f",&money,&year,&rate);
    float interest;
    interest = money * pow((1+rate),year) - money;
    interest = floor(interest * 100 + 0.5)/100;
    printf("interest = %.2f",interest);
    return 0;
}