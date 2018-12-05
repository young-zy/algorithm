#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    for(int i = 1; i<=input; i++ ){
        for(int j =1;j<=i;j++){
            printf("%d*%d=%-4d",j,i,i*j);
        }
        if(i != input){
            printf("\n");
        }
    }
    return 0;
}