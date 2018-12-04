#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int a[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int b[20];
    memset(b,-1,sizeof(b));
    for(int i = 0; i<t;i++){
        int n;
        int max;
        scanf("%d",&n);
        int sum = 0;
        int j = 0;
        while(sum < n){
            b[j] = a[j];
            sum += b[j];
            j++;
        }
        j--;
        while(sum > n || n - sum <= b[j] && n != sum){
            sum -= b[j];
            b[j] = -1;
            j--;
        }
        if(n - sum != 0){
            b[++j] = n-sum;
            sum += n-sum;
        }
        unsigned long long result = 1;
        for(int k = 0;k<=j;k++){
            result *= b[k];
            printf("%d ",b[k]);
        }
        printf("\n%llu",result);
    }
    return 0;
}