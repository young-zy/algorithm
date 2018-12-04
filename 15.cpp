#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch = 'A';
    int input;
    scanf("%d",&input);
    for(int i = input;i>0;i--){
        for(int j = i;j>0;j--){
            printf("%c ",ch);
            ch++;
            if(ch-'A' == 26){
                ch ='A';
            }
        }
        if(i != 1){
            printf("\n");
        }
    }
    return 0;
}