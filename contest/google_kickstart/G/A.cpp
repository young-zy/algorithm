#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;


unordered_map<int,int> p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 1; te <= t ;te++){
        p.clear();
        int n,m,q;
        cin>>n>>m>>q;
        int temp;
        long long ans = 0;
        for(int i = 0; i<m; i++){
            cin>>temp;
            p[temp]++;
        }
        int c;
        for(int i =0 ;i<q;i++){
            cin>>c;
            int a = c;
            int b = 1;
            while(a<= n){
                b++;
                if(!p[a]){
                    ans++;
                }
                a = c*b;
            }
            
        }
        cout<<"Case #"<<te<<": "<<ans<<endl;
    }
    return 0;
}