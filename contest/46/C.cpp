#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        unsigned long long a,b;
        cin>>a>>b;
        b += (a / 1000)*11;
        a = a % 1000;
        a /= 100;
        double res = (a + b) * 0.012 / 23;
        printf("%.3lf\n",res);
    }
    return 0;
}