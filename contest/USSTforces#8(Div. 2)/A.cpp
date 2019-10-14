#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[1000000];

set<int> se;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k; //k -> base
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        int temp = a[i];
        temp %= k;
        se.insert(temp);
    }
    for(auto it:se){
        for(auto it2:se){
            if(it == it2){
                continue;
            }
            se.insert((it+it2)%k);
        }
    }
    cout<<se.size();
    for(auto it:se){
        cout<<it<<" ";
    }
    
    return 0;

}