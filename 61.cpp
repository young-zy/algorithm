#include<bits/stdc++.h>

using namespace std;

int sign(int a){
    if(a < 0){
        return -1;
    }else if(a == 0){
        return a;
    }else{
        return 1;
    }
}

int main(){
    int input;
    scanf("%d",&input);
    printf("sign(%d) = %d",input,sign(input));
    return 0;
}