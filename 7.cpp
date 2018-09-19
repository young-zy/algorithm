#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    int count=0;
    for(int i = floor(input/5); i>0; i --){
        int temp = i*5;
        for(int j = floor((input - temp)/2); j > 0;j --){
            int temp2 = temp + j*2;
            for(int k = floor(input - temp2) ;k>0;k--){
                int temp3 = temp2 + k;
                if(temp3 == input){
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",i,j,k,i+j+k);
                    count++;
                } 
            }
        }
    }
    printf("count = %d",count);
    return 0;
}