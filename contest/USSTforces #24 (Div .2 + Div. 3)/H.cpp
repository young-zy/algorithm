#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int m,r;
    cin>>m>>r;
    for(int i = 1 ; i<=m;i++){
        double ans = 0;
        for(int j = 0; j<i*i;j++){
            double v = floor((double)j/i)+1;
            double u = i+1+(j%m);
            if(u > i && v > i || u <= i && v<=i){
                ans += fabs(u-v)*2;
            }else{
                if(u > i){
                    u -= i;
                }else{
                    v -= i;
                }
                if(u == v){
                    ans += 2;
                }else{
                    ans += 2*fabs(u-v) + sqrt(2);
                }
            }
        }
        printf("%.6lf\n",ans/i/i);
    }
    return 0;
}