#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    while(1){
        scanf("%d",&num);
        if(num == 0){
            break;
        }else{
            int temp = 0;
            int n;
            int time = 0;
            for(int i =0; i< num; i++){
                scanf("%d",&n);
                if(n > temp){
                    time += 6 * (n - temp);
                }else if(n < temp){
                    time += 4 * (temp - n);
                }
                time += 5;
                temp = n;
            }
            printf("%d\n", time);
        }
    }
    return 0;
}