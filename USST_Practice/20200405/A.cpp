#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

long long a[20005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i =0 ; i<n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int flag = 0;
    for(int i = 0; i<n-2 ; i++){
        if(a[i] + a[i+1] > a[i+2]){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"possible";
    }else{
        cout<<"impossible";
    }
    return 0;
}