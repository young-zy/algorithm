#include<bits/stdc++.h>

using namespace std;

long a[300005];
long long sum[30];
int main(){
    long n;
    int x;
    cin>>n>>x;
    int num = 0;
    for(long i = 0; i<n ; i ++){
        scanf("%ld",&a[i]);
        if(a[i] > 0){
            num++;
        }
    }
    if(x > 0 && num == 0){
        long long sum = 0;
        for(long i = 0; i<n ; i++){
            sum += a[i]; 
        }
        if(sum< 0 ){
            sum = 0;
        }
        cout<<sum;
        return 0;
    }else if(num == n && x < 0){
        long long sum = 0;
        for(long i = 0; i<n ; i++){
            sum += a[i]; 
        }
        if(sum< 0 ){
            sum = 0;
        }
        cout<<sum;
        return 0;
    }else{
        long long maxnum2 = 0;
        sum[0] = 0;
        for(long i = 1; i<= n ; i++){
            sum[i] = sum[i-1] + a[i-1];
        }
        if(x > 0){
            long maxl = 0;
            long maxr = 0;
            long long maxnum = 0;
            for(long i = 0; i<n ; i ++){
                for(long j = i; j<=n ;j++){
                    if(sum[j]-sum[i] > maxnum){
                        maxl = i;
                        maxr = j-1;
                        maxnum = sum[j]-sum[i] ;
                    }
                }
            }
            for(long i = maxl+1; i<=maxr+1;i++){
                sum[i] = sum[i-1] + a[i-1] * x;
            }
            for(long i = maxr+2; i<=n;i++){
                sum[i] = sum[i-1] + a[i-1];
            }
            for(long i = 0; i<n ; i ++){
                for(long j = i; j<=n ;j++){
                    if(sum[j]-sum[i] > maxnum2){
                        maxnum2 = sum[j]-sum[i];
                    }
                }
            }
        }else{
            long minl = 0;
            long minr = 0;
            long long minnum = 999999999999;
            for(long i = 0; i<n ; i ++){
                for(long j = i; j<=n ;j++){
                    if(sum[j]-sum[i] < minnum){
                        minl = i;
                        minr = j-1;
                        minnum = sum[j]-sum[i];
                    }
                }
            }
            for(long i = minl+1; i<=minr+1;i++){
                sum[i] = sum[i-1] + a[i-1] * x;
            }
            for(long i = minr+2; i<=n;i++){
                sum[i] = sum[i-1] + a[i-1];
            }

            for(long i = 0; i<n ; i ++){
                for(long j = i; j<=n ;j++){
                    if(sum[j]-sum[i] > maxnum2){
                        maxnum2 = sum[j]-sum[i];
                    }
                }
            }
        }
        cout<<maxnum2;
    }
    
    return 0;
}