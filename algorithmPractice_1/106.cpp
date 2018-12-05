#include<bits/stdc++.h>

using namespace std;

int main(){
    int year,wt;
    scanf("%d %d",&year,&wt);
    int a;
    double result;
    if(year<5){
        a = 30;
    }else{
        a = 50;
    }
    if(wt>40){
        result = (double)40 * a + (wt - 40)*a*1.5;
    }else{
        result = (double)wt * a;
    }
    printf("%.2lf",result);
    system("pause");
    return 0;
}