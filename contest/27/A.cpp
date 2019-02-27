#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(~scanf("%d",&n)){
        int flag = 0;
        int a[n];
        int b[n];
        memset(b,0,sizeof(b));
        for(int i =0 ; i<n;i++){
            scanf("%d",&a[i]);
        }
        int count = 1;
        while(1){
            int record = 0;
            if(count == 1){
                count = 0;
            }else if(count == 0){
                printf("Yes\n");
                break;
            }else{
                printf("No\n");
                break;
            }
            for(int i = 0; i<n;i++){
                if(a[i]>a[i+1]){
                    count++;
                    record = i;
                }
            }
            if(count == 1){
                int temp = a[record];
                a[record] = a[record+1];
                a[record+1] = temp;
            }
        }
    }
    return 0;
}