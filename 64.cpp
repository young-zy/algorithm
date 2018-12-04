#include<bits/stdc++.h>

using namespace std;

int main(){
    double x1,x2,y1,y2,x3,y3;
    double a,b,c;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
    a = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    b = sqrt(pow((x2-x3),2)+pow((y2-y3),2));
    c = sqrt(pow((x1-x3),2)+pow((y1-y3),2));
    if(a + b > c && b + c > a && a +c >b){
        double L = a + b+ c;
        double A =  sqrt((L/2)*(L/2-a)*(L/2-b)*(L/2-c));
        printf("L = %.2lf, A = %.2lf",L,A);
    }else{
        printf("Impossible");
    }
    return 0;
}