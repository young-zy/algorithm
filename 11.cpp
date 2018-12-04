#include<bits/stdc++.h>

using namespace std;

int main(){
    char a;
    double ans;
    int temp;
    scanf("%lf",&ans);
    while(1){
        scanf("%c",&a);
        if(a == '='){
            break;
        }
        scanf("%d",&temp);
        switch(a){
            case '+' :
                ans += temp;
                break;
            case '-':
                ans -= temp;
                break;
            case '*':
                ans *= temp;
                break;
            case '/':
                if(temp == 0){
                    printf("ERROR");
                    return 0;
                }
                ans /= temp;
                break;
            default:
                    printf("ERROR");
                    return 0;
        }
    }
    printf("%.0lf",ans);
    return 0;
}