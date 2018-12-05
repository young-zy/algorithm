#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch;
    scanf("%c",&ch);
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' &&ch <= 'z'){
        printf("character");
    }else if(ch >= '0' && ch <= '9'){
        printf("digit");
    }else{
        printf("ERROR");
    }
    system("pause");
    return 0;
}