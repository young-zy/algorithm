#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

double s[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m,r;
    cin>>m>>r;
    double t = sqrt(2) * r;
    s[0] = 0;
    s[1] = 2*r;
    s[2] = 2*r +t;
    s[3] = 2*r + t *2;
    for(int i = 4; i<=m;i++){
        s[i] = s[i-1] + 2*r;
    }
    for(int i = 1; i<=m;i++){
        s[i] = s[i-1] + s[i];
    }
    double ans = 0;
    for(int i = 1; i<=m;i++){
        ans += s[i]+s[m-i+1]-2*r;
    }

    // double res = 0;
    // for(int i = 0; i<m;i++){
    //     res += 2;
    //     if(i>0 || i+1 < m){
    //         res += (2+sqrt(2.0));
    //     }
    //     if (i > 0) {
    //         double v = i - 1;
    //         res += v * (v + 1);
    //         res += 2.0 * sqrt(2.0) * v;
    //     }
    //     if (i + 1 < m) {
    //         double v = m - 2 - i;
    //         res += v * (v + 1);
    //         res += 2.0 * sqrt(2.0) * v;
    //     }
    // }    
    printf("%.10lf",ans/m/m);
    return 0;
}