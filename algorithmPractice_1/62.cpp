#include<bits/stdc++.h>

using namespace std;

int main(){
    int letter = 0;
    int blank = 0;
    int digit = 0;
    int other = 0;
    for(int i =0;i<10;i++){
        char ch;
        ch = getchar();
        if(ch == '\n'){
            blank++;
            continue;
        }
        if(ch >= 'A' &&ch <='z'){
            letter ++;
            continue;
        }else if(ch >='0' && ch <='9'){
            digit++;
            continue;
        }else if(ch == ' '){
            blank ++;
            continue;
        }else{
            other ++;
            continue;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
    return 0;
}