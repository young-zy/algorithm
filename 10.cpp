#include<bits/stdc++.h>

using namespace std;

int main(){
    int quant;
    int max;
    int maxfooter;
    scanf("%d",&quant);
    for(int i = 0;i<quant;i++){
        int temp;
        scanf("%d",&temp);
        if(i == 0){
            max = temp;
            maxfooter = 0;
        }
        if(temp> max){
            max = temp;
            maxfooter = i;
        }
    }
    printf("%d %d",max ,maxfooter);
    return 0;
}