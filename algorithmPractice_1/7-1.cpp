#include<bits/stdc++.h>

using namespace std;

int main (){
    int x,y;
    scanf("%d %d",&x,&y);
    int a = y/x;
    int count = 0;
    for(int i =1; i<sqrt(a); i++){
        if(a%i == 0){
            if(y/x/i % i == 0 && i != 1){
                continue;
            }
            count ++;
        }
    }
    printf("%d",count * 2);
    return 0;
}