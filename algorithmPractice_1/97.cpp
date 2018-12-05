#include<bits/stdc++.h>

using namespace std;

int main(){
    int hh,mm,ss;
    int sec;
    scanf("%d:%d:%d",&hh,&mm,&ss);
    scanf("%d",&sec);
    ss+=sec;
    if(ss>=60){
        mm+=1;
        ss-=60;
    }
    if(mm>=60){
        hh+=1;
        mm-=60;
    }
    if(hh == 24){
        hh = 0;
    }
    printf("%02d:%02d:%02d",hh,mm,ss);
    return 0;
}