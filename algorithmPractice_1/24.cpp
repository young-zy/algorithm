#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    int odd= 0;
    int even = 0;
    int temp;
    scanf("%d",&num);
    for(int i = 0;i < num ; i++){
        scanf("%d",&temp);
        if(temp % 2 == 0){
            even ++;
        }else{
            odd++;
        }
    }
    printf("%d %d",odd,even);
    return 0;
}