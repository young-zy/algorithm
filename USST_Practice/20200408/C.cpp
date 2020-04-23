#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    int b;
    int temp;
    sort(a,a+n);
    for(int i = 0; i< q; i++){
        cin>>b>>temp;
        int base = 1;
        while(b--){
            base*=10;
        }
        int res = -1;
        for(int j = 0; j< n;j++){
            if(a[j] % base == temp){
                res = a[j];
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}