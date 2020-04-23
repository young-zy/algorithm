#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

const long long mod = 99997876;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d;
    cin>>n>>d;
    long long count = 0;
    deque<int> dq;
    long long temp;
    for(int i = 1; i<=n ; i++){
        cin>>temp;
        dq.push_back(temp);
        if(dq.size()>=3){
            if(dq.back()-dq.front() <= d){
                long long temp = dq.size();
                temp = ((temp-1)*(temp-2)/2)%mod;
                count = (count+temp)%mod;
            }else{
                while(dq.back()-dq.front() > d){
                    dq.pop_front();
                }
                if(dq.size()>=3){
                    long long temp = dq.size();
                    temp = ((temp-1)*(temp-2)/2)%mod;
                    count = (count+temp)%mod;
                }
            }
        }
    }
    cout<<count;
    return 0;
}