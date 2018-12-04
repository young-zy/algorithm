#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i<t;i++){
        int n;
        scanf("%d",&n);
        int a[n];
        for(int j = 0;j<n;j++){
            scanf("%d",&a[j]);
        }
        int length = 1;
        int temp = 1;
        for(int j = 1; j<n;j++){
            if(a[j] - a[j-1] == 1){
                temp++;
            }else{
                if(temp > length){
                    length = temp;
                }
                temp = 1;
                j++;
            }
        }
        printf("%d",length);
    }
    
    return 0;
}