#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[1000005][6];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;
    cin>>n>>d;
    for(int i = 0; i<n ; i++){
        for(int j = 0;j<d; j++){
            cin>>a[i][j];
        }
    }
    long long ans = 0;
    for(int den = 0; den < (1<<d); den++){
        long long minnum = INF;
        long long maxnum = -INF;
        for(int i = 0; i<n;i++){
            long long t = 0;
            for(int j = 0; j<d;j++){
                if((1<<j) & den){
                    t+=a[i][j];
                }else{
                    t-=a[i][j];
                }
            }
            minnum = min(minnum,t);
            maxnum = max(maxnum,t);
        }
        ans = max(ans,maxnum - minnum);
    }
    cout<<ans;
    return 0;
}