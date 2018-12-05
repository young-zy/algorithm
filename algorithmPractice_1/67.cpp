#include<bits/stdc++.h>

using namespace std;

int main(){
    long int a,n;
    scanf("%ld %ld",&a,&n);
    double h = (double)a;
    double distance = 0;
    double height = 0;
    for(int i = 0; i<n;i++){
        distance += h;
        if(i != n-1){
            h /= 2;
            distance += h;
        }
    }
    height = h/2;
    if(n == 0){
        height = 0;
    }
    printf("%.1lf %.1lf",distance,height);
    return 0;
}