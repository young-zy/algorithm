#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    if(input<= 2000 || input > 2100){
        printf("Invalid year!");
        return 0;
    }
    if(input >2000 && input < 2004){
        printf("None");
    }
    for(int i = 2004;i<=input;i=i+4){
        if(i == 2100){
            break;
        }
        printf("%d\n",i);
    }
    return 0;
}