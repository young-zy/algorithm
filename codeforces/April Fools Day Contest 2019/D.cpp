#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i =0 ;i < n ; i++){
        cin>>a[i];
    }
    int temp = a[2];
    sort(a,a+n);
    cout<<2+(temp^a[0]);
    return 0;
}