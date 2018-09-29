#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch[] = "[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit";
    float a[4] = {3.00,2.5,4.1,10.2};
    printf("%s",ch);
    int input;
    scanf("%d",&input);
    int count = 0;
    while(input != 0 &&count < 5){
        if(input>0 && input<=4){
            printf("\nprice = %.2f",a[input - 1]);
        }else{
            printf("\nprice = 0.00");
        }
        if(count != 4){
            scanf("%d",&input);
        }
        count++;
    }
    return 0;
}