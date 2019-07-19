#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int bi[31];
int nxt[4000000][2];
int tot = 1;

void insert(int x){
    int p = 1;
    for(int i = 30 ; i>=0;i--){
        bi[i] = x&1;
        x>>=1;
    }
    for(int i = 0; i< 31;i++){
        int temp = bi[i];
        if(!nxt[p][temp]){
            nxt[p][temp] = ++tot;
        }
        p = nxt[p][temp];
    }
}

int query(int x){
    int ans = 0;
    int p = 1;
    for(int i = 30 ; i>=0;i--){
        bi[i] = x&1;
        x>>=1;
    }
    for(int i = 0; i< 31;i++){
        int temp = bi[i]^1;
        ans<<=1;
        if(!nxt[p][temp]){
            temp ^= 1;
        }
        ans |= temp;
        p = nxt[p][temp];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int ans = 0;
    memset(nxt,0,sizeof(nxt));
    for(int i = 0; i<n ; i++){
        int x;
        cin>>x;
        insert(x);
        ans = max(ans,x ^ query(x));
    }
    cout<<ans;
    return 0;
}