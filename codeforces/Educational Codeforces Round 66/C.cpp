#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t;te++){
        int n,k;
        cin>>n>>k;
        long long sum = 0;
        for(int i = 0; i<n ; i++){
            cin>>a[i];
        }
        int l = n/2-1;
        int r;
        r = l+1;
        long long res = 0;
        int last = 0;
        for(int i = 0; i<k+1 ;i++){
            if(l == -1){
                res += a[r];
                r++;
                last = a[r];
                continue;
            }
            if(r == n){
                res += a[l];
                last = a[l];
                l++;
                continue;
            }
            int avg = res / (i+1);
            if(fabs(avg - a[l]) < fabs(avg - a[r])){
                res += a[l];
                last = a[l];
                l--;
            }else{
                res += a[r];
                last = a[r];
                r++;
            }
        }
        long long res2 = (long double)res/(k+1);
        if(res % (k+1) != 0){
            if(fabs(res/(k+1) - last) < fabs(res/(k+1)+1 - last)){
                res2 = res/(k+1);
            }else{
                res2 = res/(k+1)+1;
            }
        }else{
            res2 = res/(k+1);
        }
        cout<<res2<<endl;
    }   
    return 0;
}