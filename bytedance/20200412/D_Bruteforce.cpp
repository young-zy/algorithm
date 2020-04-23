#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

const int maxn = 100005;
// const int maxn = 100;

int a[maxn];
long long res[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l = 0;
        int r = 0;
        for(int i =0;i<n;i++){
            cin>>a[i];
        }
        memset(res,0,sizeof(res));
        for(int i = 0; i<n ; i++){
            int cur = i-1;
            while(cur>=0){
                if(a[cur] <= a[i]){
                    res[i]++;
                }else{
                    break;
                }
                cur--;
            }
            cur = i+1;
            while(cur<n){
                if(a[cur] <= a[i]){
                    res[i]++;
                }else{
                    break;
                }
                cur++;
            }
        }
        for(int i = 0; i<n ; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}