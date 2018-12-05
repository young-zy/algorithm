#include<bits/stdc++.h>

using namespace std;

int main(){
    double temp,result;
    temp = 0;
    double eps;
    scanf("%le",&eps);
    int i = 0;
    while(1){
        if(i == 0){
            result += 1;
            i++;
            continue;
        }
        unsigned long long a = 1;
        for(int j = 1;j<=i;j++){
            a*=j;
        }
        unsigned long long b = 1;
        for(int j = 3;j<=2*i+1;j+=2){
            b*=j;
        }
        temp = (double)a/b;
        if(temp < eps){
            result+=temp;
            result*=2;
            printf("PI = %.5lf",result);
            break;
        }else{
            result += temp;
        }
        i++;
    }
    system("pause");
    return 0;
}