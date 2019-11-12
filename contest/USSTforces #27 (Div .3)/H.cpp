#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
 
using namespace std;
 
set<long long> se;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int flag = 0;
    long long temp;
    for(int i = 0; i<n ; i++){
        cin>>temp;
        se.insert(temp);
    }
    deque<long long> dq;
    for(auto it:se){
        // long long t = se.size();
        // se.insert(it*2);
        // if(se.size() == t){
        //     continue;
        // }else{
        //     if(it == *(--se.rbegin())){
        //         break;
        //     }
        //     flag = 1;
        //     break;
        // }
        dq.push_back(it);
    }
    for(int i = 0; i<dq.size()-1 ; i++){
        if(dq[i]*2 > dq[i+1]){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}