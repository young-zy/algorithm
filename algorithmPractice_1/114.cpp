#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch[15];
    strcpy(ch,"I Love GPLT");
    for(int i = 0;i< 11;i++){
        printf("%c",ch[i]);
        if(i!=10){
            printf("\n");
        }
    }
    return 0;
}