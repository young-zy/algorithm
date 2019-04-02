#include<bits/stdc++.h>

using namespace std;

int Euclid(int a,int b){
    if(b>a){
        b=b+a;
        a = b-a;
        b = b-a;
    }
    if(a % b !=0){
        return Euclid(b,a % b);
    }else{
        return b;
    }
}

int quickgcd(int a,int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(!(a&1) && !(b&1)){
        return quickgcd(a>>1,b>>1)<<1;
    }else if(!(b & 1)){
        return quickgcd(a,b>>1);
    }else if(!(a & 1)){
        return quickgcd(a>>1,b);
    }else{
        //return quickgcd(abs(a-b),min(a-b));
    }
}


int main(){
    
    return 0;
}