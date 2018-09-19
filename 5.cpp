#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    float exceed;
    scanf("%d %d",&a,&b);
    if(a<b+b*0.1){
        printf("OK");
    }else if(a<b+b*0.5){
        exceed = (float)(a - b)/b;
        exceed = floor(exceed*100+0.5);
        printf("Exceed %.0f%%. Ticket 200",exceed);
    }else{
        exceed = (float)(a - b)/b;
        exceed = floor(exceed*100+0.5);
        printf("Exceed %.0f%%. License Revoked",exceed);
    }
    return 0;
}