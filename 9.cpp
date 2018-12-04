#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    int num = 1;
    scanf("%d",&input);
    for(;input>1;input--){
        num = (num + 1)*2;
    }
    printf("%d",num);
    return 0;
}