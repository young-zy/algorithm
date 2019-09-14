#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d",&t);
    for(int te = 0; te< t ; te++){
        double n,m;
        scanf("%lf %lf",&n,&m);
        double ans = 0;
        double add = 1;
        for(int i = 0;i<n-1;i++){
            add *= (double)(n-i)/n;
            ans += add / n;
        }
        printf("Case #%d: %.6lf ",te+1,ans);
        printf("%lf",1-1/m);
        printf("\n");
    }
    return 0;
}