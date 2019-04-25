#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int dp[n];
    for(int i = 0; i < n ; i++){
        scanf("%d",&a[i]);
    }
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i<n;i++){
        for(int j = i-1;j>=0;j--){
            if(a[j] >= a[i] && dp[j]+1 > dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    int maxnum = 0;
    for(int i = 0; i< n; i++){
        maxnum = max(maxnum,dp[i]);
    }
    cout<<maxnum<<" ";
    int count = 0;
    for(int i = 0; i<n-1;i++){
        if(a[i+1]>a[i]){
            count++;
        }
    }
    cout<<count+1;
    return 0;
}