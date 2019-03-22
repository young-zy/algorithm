#include<bits/stdc++.h>

using namespace std;

int main(){
    int r1,r;
    scanf("%d %d",&r1,&r);
    double pi = 3.1415926;
    double s1 = pi*r1*r1;
    double s = pi*r*r;
    int num = s1/s;
    if(num % 2 == 0){
        cout<<"lst";
    }else{
        cout<<"rhy";
    }
    return 0;
}