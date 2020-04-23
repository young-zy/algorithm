#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,x;
    cin>>q>>x;
    map<int, int> ma;
    int cur = 0;
    int res = 0;
    for(int i = 0 ;i< q; i++){
        int y;
        cin>>y;
        ma[y%x]++;
        while(1){
            if(ma[cur]){
                ma[cur] -= 1;
                cur = (cur+1)%x;
                res++;
            }else{
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}