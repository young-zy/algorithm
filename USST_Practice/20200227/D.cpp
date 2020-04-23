#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te< t ;te++){
        int n;
        cin>>n;
        int sum = 0;
        int maxnum = -INF;
        int minnum = INF;
        for(int i = 0; i<n;i++){
            cin>>a[i];
        }
        for(int i =0 ; i<n ; i++){
            if(i > 0 && a[i] == -1 && a[i-1] != -1){
                maxnum = max(maxnum, a[i-1]);
                minnum = min(minnum, a[i-1]);
            }
            if(i < n-1 && a[i] == -1 && a[i+1] != -1){
                maxnum = max(maxnum, a[i+1]);
                minnum = min(minnum, a[i+1]);
            }
        }
        long long k = ((long long)minnum+maxnum)/2;
        long long m = 0;
        if(a[0] == -1){
            a[0] = k;
        }
        for(int i =1; i<n ; i++){
            if(a[i] == -1){
                a[i] = k;
            }
            m = max(m,(long long)fabs(a[i] - a[i-1]));
        }
        cout<<m<<" "<<k<<endl;
    }
    return 0;
}