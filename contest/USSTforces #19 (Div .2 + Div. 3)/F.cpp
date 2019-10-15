#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    a[1] = 1;
    for(int i = 2; i<=50;i++){
        a[i] = 2*a[i-1]+(1LL<<(i-1));
    }
    n--;
    long long ans = 0;
    for(int i = 0; i<50;i++){
        if(n & (1LL<<i)){
            ans+=a[i]+(1LL<<i);
        }
    }
    cout<<ans;
    return 0;
}