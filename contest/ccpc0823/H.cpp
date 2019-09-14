#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int dq[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0 ; te < t ; te++){
        int n,k;
        cin>>n>>k;
        long long ans = 0;
        int temp;
        for(int i = 0; i<n;i++){
            cin>>dq[i];
        }
        long long time = 0;
        sort(dq,dq+n,greater<int>());
        time += k;
        queue<int> qu;
        int i = 0;
        qu.push(dq[i++]);
        while(i < n){
            long long temp = qu.front();
            qu.pop();
            int count = temp/k;
            time += count * k;
            for(int j = 0; j<count && i < n ; j++){
                qu.push(dq[i++]);
            }
            if(temp % k < k - (temp%k)){
                time += temp % k;
            }else{
                if(i < n){
                    time += k;
                    qu.push(dq[i++]);
                }
            }
        }
        while(!qu.empty()){
            time += qu.front();
            qu.pop();
        }
        cout<<time<<endl;
    }
    return 0;
}