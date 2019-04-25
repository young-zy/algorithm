#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

unsigned long long a[35];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int k;
    cin>>k;
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i<=k;i++){
        a[i] = a[i-1]* (4*i-2)/(i+1);
    }
    cout<<a[k]<<" "<<k+1;
    return 0;
}