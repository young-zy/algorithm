#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long s;
    cin>>s;
    long long ans = 0;
    for(long long i = sqrt(2*s) + 1; i>=1;i--){
        if((2*s +i -i*i) % (2 *i) == 0 && (2*s +i -i*i) > 0){
            ans = i;
            break;
        }
    }
    long long start = (2*s - ans*ans + ans)/(2*ans);
    cout<<start<<" "<<ans+start-1;
    return 0;
}