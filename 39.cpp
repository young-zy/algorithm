#include<bits/stdc++.h>

using namespace std;

int main(){
    int input;
    scanf("%d",&input);
    int i = 0;
    int j = 0;
    int k = 1;
    int temp;
    int month;
    for(month = 1; i+j+k < input;month++){
        temp = j;
        j = k;
        k = i;
        i += temp;
    }
    printf("%d",month-3);
    
    return 0;
}