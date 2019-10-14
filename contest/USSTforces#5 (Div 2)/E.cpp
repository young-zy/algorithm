#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    unsigned long long a,b;
    cin>>a>>b;
    int la = 0,lb = 0;
    unsigned long long temp = a;
    unsigned long long ans = a-b;
    if(ans % 2 ==0){
        ans /=2;
        cout<<ans<<" "<<(b^ans);
    }else{
        cout<<"-1";
    }
    return 0;
}