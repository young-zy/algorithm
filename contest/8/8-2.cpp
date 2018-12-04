#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int a[4] = {
        t,t+1,t+2,t+3
    };
    int count = 0;
    for(int i = 0; i<24;i++){
        if(a[0] == 0){
            next_permutation(a,a+4);
            continue;
        }
        printf("%d%d%d",a[0],a[1],a[2]);
        if(count != 5){
            printf(" ");
        }
        count++;
        if(count == 6 && i!=23){
            count = 0;
            printf("\n");
        }
        next_permutation(a,a+4);
    }
    
    return 0;
}