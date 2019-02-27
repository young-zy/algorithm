#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i =0 ;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i]>sum+1){
            break;
        }else{
            sum+=a[i];
        }
    }
    printf("%lld",sum+1);
    //system("pause");
    return 0;
}