#include<bits/stdc++.h>

using namespace std;

double length(int x1,int y1,int x2,int y2);

int main(){
    int xa,ya,xb,yb,xc,yc;
    scanf("%d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc);
    double lengthab,lengthac,lengthbc;
    lengthab = length(xa,ya,xb,yb);
    lengthac = length(xa,ya,xc,yc);
    lengthbc = length(xb,yb,xc,yc);
    if(lengthac >= lengthbc){
        if(lengthbc >= lengthab){
            
        }else if(lengthab >= lengthac){

        }else{

        }
    }else{
        if(lengthac >= lengthab){
            
        }else if(lengthbc >= lengthac){

        }else{

        }
    }
    return 0;
}

double length(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}