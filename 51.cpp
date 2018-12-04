#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch;
    int i;
    int count = 0;
    while(1){
        scanf("%c",&ch);
        if(ch == '.'){
            if(count != 0 && i != 0){
                printf(" ");
            }
            if(i != 0){
                printf("%d",i);
            }
            break;
        }
        if(ch == ' '){
            if(count != 0 && i != 0){
                printf(" ");
            }
            if(i != 0){
                printf("%d",i);
                count++;
            }
            i = 0;
            continue;
        }
        i++;
    }
    return 0;
}