#include<bits/stdc++.h>

using namespace std;

int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a + b > c && b + c > a && a +c >b){
        double L = a + b+ c;
        double A =  sqrt((L/2)*(L/2-a)*(L/2-b)*(L/2-c));
        printf("area = %.2lf; perimeter = %.2lf",A,L);
    }else{
        printf("These sides do not correspond to a valid triangle");
    }
    return 0;
}