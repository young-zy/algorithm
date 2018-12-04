#include<bits/stdc++.h>

using namespace std;

int main(){
    float a,b,c;
    float delta = 0;
    scanf("%f %f %f",&a,&b,&c);
    if(fabs(a)<DBL_EPSILON && fabs(b) < DBL_EPSILON){
        if(fabs(c) < DBL_EPSILON){
            printf("Zero Equation");
        }else{
            printf("Not An Equation");
        }
    }else{
        if(fabs(a)<DBL_EPSILON){
            printf("%.2f",-floor(c/b*100+0.5)/100);
            return 0;
        }
        delta = pow(b,2) - 4 * a * c;
        if(delta > 0){
            float first,second;
            first = (-b + sqrt(delta))/2/a;
            second = (-b -sqrt(delta))/2/a;
            printf("%.2f\n%.2f",floor(first*100+0.5)/100,floor(second*100+0.5)/100);
        }else if(delta == 0){
            float first;
            first = -b/2/a;
            printf("%.2f",floor(first*100+0.5)/100);
        }else{
            float real,imaginary;
            real = -b/2/a;
            imaginary = sqrt(-delta)/2/a;
            printf("%.2f+%.2fi\n%.2f-%.2fi",floor(real*100+0.5)/100,floor(imaginary*100+0.5)/100,floor(real*100+0.5)/100,floor(imaginary*100+0.5)/100);
        }
    }
    
    return 0;
}