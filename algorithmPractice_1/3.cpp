#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    int sum = 0;
    int temp;
    int count = 0;
    float average;
    scanf("%d",&num);
    if(num>0){
        for(int i = 0; i < num; i++){
            scanf("%d",&temp);
            sum += temp;
            if(temp >= 60){
                count++;
            }
        }
        average = (float)sum/num;
        average = floor(average*10+0.5)/10;
    }else{
        average = 0.0;
        count = 0.0;
    }
    printf("average = %.1f\n",average);
    printf("count = %d",count);
    return 0;
}