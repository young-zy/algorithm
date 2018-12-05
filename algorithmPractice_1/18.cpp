#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    char ch;
    int ans;
    scanf("%d %c %d",&a,&ch,&b);
    switch(ch){
        case '+':
            ans = a + b;
            break;
        case '-':
            ans = a - b;
            break;
        case '*':
            ans = a * b;
            break;
        case '/':
            ans = a / b;
            break;
        case '%':
            ans = a % b;
            break;
        default:
            printf("ERROR");
            return 0;
    }
    printf("%d",ans);
    return 0;
}