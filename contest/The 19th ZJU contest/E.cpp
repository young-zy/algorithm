#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int te = 0; te < t;te++){
        int n;
        cin>>n;
        long long a[n];
        long long b[n];
        for(int i = 0; i<n ; i++){
            cin>>a[i];
        }
        for(int i = 0; i< n; i++){
            cin>>b[i];
        }
        int flag = 1;
        for(int i = n-1;i > 0;i--){
            if(b[i] >= a[i]){
                b[i-1] += b[i]-a[i];
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1 && b[0] >= a[0]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}