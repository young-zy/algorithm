#include<bits/stdc++.h>

using namespace std;

int main(){
    int d;
    scanf("%d",&d);
    d+=2;
    if(d>7){
        d-=7;
    }
    printf("%d",d);
    return 0;
}