#include<bits/stdc++.h>

using namespace std;

int main(){
        int T;
    int time = 0;
    scanf("%d",&T);
    int lengtha = 0;
    int lengthb = 0;
    int rabbitrest = 0;
    int rabbitresttime = 0;
    for(;time<T;time++){
        if(rabbitrest !=10){
            if(rabbitresttime == 0){
                lengtha += 9;
                rabbitrest++;
            }else{
                rabbitresttime--;
            }
        }else{
            rabbitrest = 0;
            if(lengtha>lengthb){
                rabbitresttime = 29;
            }
        }
        lengthb += 3;
    }
    if(lengtha>lengthb){
        printf("^_^ %d",lengtha);
    }else if(lengtha<lengthb){
        printf("@_@ %d",lengthb);
    }else{
        printf("-_- %d",lengtha);
    }
    return 0;
}