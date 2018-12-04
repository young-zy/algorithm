#include<bits/stdc++.h>

using namespace std;

int main(){
    double d,t;
    int r;
    int count =1;
    while(1){
        scanf("%lf %d %lf",&d,&r,&t);
        if(r == 0){
            break;
        }
        double dis,mph;
        dis =  d * 3.1415927 * r / 12 / 5280;
        mph = dis/t * 60*60; 
        printf("Trip #%d: %.2lf %.2lf\n",count,dis,mph);
        count++;
    }
    return 0;
}