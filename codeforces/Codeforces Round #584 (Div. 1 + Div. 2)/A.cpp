#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

set<int> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp;
    for(int i = 0; i<n ;i++){
        cin>>temp;
        a.insert(temp);
    }
    int ans = 0;
    for(int i = 2; i<=100;i++){
        if(a.empty()){
            break;
        }
        int flag = 0;
        for(auto it = a.begin();it!= a.end();){
            if(*it%i == 0){
                if(flag == 0){
                    flag = 1;
                    ans++;
                }
                a.erase(it++);
            }else{
                it++;
            }
        }
    }
    cout<<ans;
    return 0;
}