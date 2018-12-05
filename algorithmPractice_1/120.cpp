#include<bits/stdc++.h>

using namespace std;

int main(){
    char a[11];
    scanf("%s",a);
    int i =0;
    while(i<11){
        if(i == 0){
            a[i] = toupper(a[i]);
        }else{
            a[i] = tolower(a[i]);
        }
        i++;
    }
    printf("Hello,%s!",a);
    return 0;
}