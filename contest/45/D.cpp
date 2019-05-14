#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;
    cin>>n>>t;
    int sum = 0;
    int minnum = INF;
    for(int i = 0; i<n ; i++){
        int temp;
        cin>>temp;
        if(temp > t){
            dq.clear();
            sum = 0;
            continue;
        }
        while(sum + temp > t ){
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(temp);
        sum += temp;
        if(sum == t){
            minnum = min((int)dq.size(),minnum);
        }
    }
    if(minnum == INF){
        cout<<"No";
    }else{
        cout<<minnum;
    }
    return 0;
}