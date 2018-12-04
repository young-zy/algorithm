#include<bits/stdc++.h>

using namespace std;

int main(){
    int count = 0;
    int input;
    scanf("%d",&input);
    for(int i = 1;i<=input;i++){
        int temp = i;
        int f = 0;
        int g = 0;
        while(temp > 0){
            f += temp % 10;
            temp /= 10;
        }
        temp = i;
        while(temp > 0){
            g += temp % 2;
            temp /= 2;
        }
        if(f == g){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
