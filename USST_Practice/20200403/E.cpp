#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int n;

vector<vector<int> > se;

vector<int> b(15);

int ans = INF;

void dfs(int index){
    if(index == n){
        ans = min(ans,(int)se.size());
        return;
    }
    for(auto it:se){
        int flag = 1;
        for(auto it2:it){
            if(__gcd(it2, b[index]) != 1){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            it.push_back(b[index]);
            dfs(index+1);
            it.pop_back();
        }
    }
    vector<int> ve;
    ve.push_back(b[index]);
    se.push_back(ve);
    dfs(index+1);
    se.pop_back();
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>b[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}