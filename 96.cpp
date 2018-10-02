#include<bits/stdc++.h>

using namespace std;

int main(){
    int year,month,day;
    int isLeap = 0;
    int result = 0;
    scanf("%d/%d/%d",&year,&month,&day);
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        isLeap = 1;
    }
    switch (month - 1){
        case 11:
            result += 30;
        case 10:
            result += 31;
        case 9:
            result += 30;
        case 8:
            result += 31;
        case 7:
            result += 31;
        case 6:
            result += 30;
        case 5:
            result += 31;
        case 4:
            result += 30;
        case 3:
            result += 31;
        case 2:
            if(isLeap){
                result +=29;
            }else{
                result +=28;
            }
        case 1:
            result += 31;
    }
    result += day;
    printf("%d",result);
    return 0;
}