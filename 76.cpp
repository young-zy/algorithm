#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    int a = -1;
    int newnum = input;
    int count = 1;
    while(newnum != a){
        a = newnum;
        newnum = 0;
        int b = a;
        while(b != 0){
            newnum += b % 10;
            b /= 10;
        }
        newnum *= 3;
        newnum ++;
        if(count != 1){
            printf("\n");
        }
        printf("%d:%d",count,newnum);
        count++;
    }
    return 0;
}