#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

priority_queue<long long> x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    for(int qe = 0 ;qe < q; qe++){
        while(!x.empty()){
            x.pop();
        }
        int n,r;
        cin>>n>>r;
        int temp;
        for(int i = 0; i<n ; i++){
            cin>>temp;
            x.push(temp);
        }
        long long ans = 0;
        int offset = 0;
        while(!x.empty() && x.top() - offset > 0){
            int temp = x.top();
            while(!x.empty()&&temp == x.top()){
                x.pop();
            }
            ans++;
            offset+=r;
        }
        cout<<ans<<endl;
    }
    return 0;
}