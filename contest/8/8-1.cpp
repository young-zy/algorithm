#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    int k = 'A';
    for(int i = num; i>0;i--){
        if(i != num){
            printf("\n");
        }
        for(int j = i;j>0;j--){
            printf("%c",k);
            k++;
        }
    }
    return 0;
}