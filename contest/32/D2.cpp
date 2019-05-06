#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[300005];
int b[300005];
int gap[300005];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i< n; i  ++){
        cin>>a[i];
    }
    for(int i = 0; i< n; i ++){
        cin>>b[i];
    }
    for(int i = n-1 ; i > 0;i--){
        gap[i] = a[i] - a[i-1];
    }
    
    return 0;
}