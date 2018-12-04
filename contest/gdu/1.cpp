#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int j = 0; j<n;j++){
        int t;
        scanf("%d",&t);
        int a[t+1];
        a[0] = -1;
        int i;
        for(i = 1; i<=t;i++){
            scanf("%d",&a[i]);
        }
        for(i = 1; i<=t;i++){
            if(a[t]>a[t-1]){
                continue;
            }else{
                printf("Transform Mobility With Autonomous Driving\n");
                break;
            }
        }
        
        if(i == t+1){
            printf("WeRide.ai\n");
        }
        
    }
    return 0;
}