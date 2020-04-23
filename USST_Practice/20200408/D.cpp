#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int n,x;
    while(t--){
        cin>>n>>x;
        int temp;
        for(int i = 1; i<=n+x; i++){
            a[i] = 0;
        }
        for(int i = 1; i<=n ; i++){
            cin>>temp;
            a[temp] = 1;
        }
        for(int i = n+x; i>0 ; i--){
            int b = 0;
            for(int j = 1; j<=i ;j++){
                if(!a[j]){
                    b++;
                }
            }
            if(b <= x){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}