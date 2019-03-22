#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int resa,resb;
    resa = a;
    resb = (100-a)*b;
    if(resa*0.01 >= resb*0.0001){
        cout<<"Ben";
    }else{
        cout<<"Oak";
    }
    return 0;
}