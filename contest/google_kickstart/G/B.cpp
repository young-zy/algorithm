#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[1005];

struct trie{
    int ch[2],v;
}tr[600005*26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    for(int te = 1; te <= t ;te++){
        long long n,m;
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        long long base = 1;
        while(base <= a[n-1]){
            base <<= 1;
        }
        if(base <= m){
            base = 128;
        }
        long long aans = -1;
        for(long long i = base;i>=0;i--){
            long long ans = 0;
            for(int j = 0;j < n;j++){
                ans += i^a[j];
                if(ans > m){
                    break;
                }
            }
            if(ans <= m){
                aans = i;
                break;
            }
        }
        cout<<"Case #"<<te<<": "<<aans<<endl;
    }
    return 0;
}