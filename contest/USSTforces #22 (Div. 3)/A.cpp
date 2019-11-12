#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;
    long long ans = 0;
    ans += (1+fabs(x2-x1))*2;
    ans += (1+fabs(y2-y1))*2;
    if(x1 == x2 || y1 == y2){
        ans += 2;
    }
    cout<<ans;
    return 0;
}