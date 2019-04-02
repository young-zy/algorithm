#include<bits/stdc++.h>

using namespace std;

int main(){
    int l;
    int n;
    cin>>l>>n;
    int a[n];
    int maxi = 0;
    int mini = 0;
    for(int i = 0; i<n;i++){
        cin>>a[i];
        if(mini < min(a[i],l+1-a[i])){
            mini = min(a[i],l+1-a[i]);
        }
        if(maxi < max(a[i],l+1-a[i])){
            maxi = max(a[i],l+1-a[i]);
        }
    }
    cout<<mini<<" "<<maxi;
    
    return 0;
}