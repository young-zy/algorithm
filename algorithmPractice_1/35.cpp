#include<bits/stdc++.h>

using namespace std;

int main(){
    int num,temp;
    scanf("%d",&num);
    scanf("%d",&temp);
    int min = temp;
    for(int i = 0;i<num-1;i++){
        scanf("%d",&temp);
        if(temp < min){
            min = temp;
        }
    }
    printf("min = %d",min);
    return 0;
}