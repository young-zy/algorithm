#include<bits/stdc++.h>

using namespace std;

int a[300005];
int b[300005];

int main(){
    long n;
    cin>>n;
    for(long i = 0; i<n ; i++){
        scanf("%d",&a[i]);
    }
    for(long i = 0; i< n ; i++){
        scanf("%d",&b[i]);
    }
    long count = 0;
    for(long i =n-1; i>=0;i--){
        for(int j = 1;j<a[i] && i-j>=0;j++){
            if(b[i-j] >= 0){
                b[i-j]--;
            }else{
                continue;
            }
            if(b[i-j] == -1){
                count++;
            }
        }
    }
    cout<<n-count;
    return 0;
}