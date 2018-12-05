#include<bits/stdc++.h>

using namespace std;

int main(){
    int i = 1;
    char a[11] = "";
    char first[11];
    char second[11];
    scanf("%s",a);
    while(strcmp(a,".")){
        if(i == 2){
            strcpy(first,a);
        }
        if(i == 14){
            strcpy(second,a);
        }
        scanf("%s",a);
        i++;
    }
    if(i<=2){
        printf("Momo... No one is for you ...");
    }else if(i <=14){
        printf("%s is the only one for you...",first);
    }else{
        printf("%s and %s are inviting you to dinner...",first,second);
    }
    return 0;
}