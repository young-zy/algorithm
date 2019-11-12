#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[100005];

long long ans[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i =0 ;i<n ; i++){
        cin>>a[i];
        ans[i+1] = ans[i]^a[i];
    }
    return 0;
}