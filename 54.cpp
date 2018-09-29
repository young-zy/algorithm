#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    scanf("%d:%d",&a,&b);
    if(a>=0 &&a<12){
        printf("Only %02d:%02d.  Too early to Dang.",a,b);
        return 0;
    }else{
        if(b == 0){
            if(a == 12){
                printf("Only %02d:%02d.  Too early to Dang.",a,b);
            }
            for(int i = 0; i<a-12;i++){
                printf("Dang");
            }
        }else{
            for(int i = 0; i<a-12+1;i++){
                printf("Dang");
            }
        }
    }
    return 0;
}