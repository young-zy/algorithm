#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

const int maxn = 15;

using namespace std;

struct node{
    map<int,int> ma;
    int last;
    bool operator < (node b) const{
        return this->last < b.last;
    }
};

int b[maxn];
deque<int> dq[maxn];
long long ans;
int v;
map<node,int> mma;


void dfs(node no){
    long long temp = 0;
    if(mma[no]){
        return;
    }
    for(auto it:no.ma){
        if(it.second){
            temp += b[it.first];
        }
    }
    mma[no]++;
    ans = max(ans,temp);
    for(int i = no.last+1 ;i<=v;i++){
        if(no.ma[i]){
            continue;
        }else{
            no.last = i;
            dfs(no);
            no.ma[i]=1;
            for(auto it:dq[i]){
                no.ma[it]++;
            }
            dfs(no);
            no.ma[i] = 0;
            for(auto it:dq[i]){
                no.ma[it]--;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 1; te<=t;te++){
        mma.clear();
        ans = 0;
        cin>>v;
        for(int i = 1; i<=v ;i++){
            cin>>b[i];
            dq[i].clear();
        }
        int tempa,tempb;
        for(int i = 1; i<=v-1;i++){
            cin>>tempa>>tempb;
            dq[tempa].push_back(tempb);
            dq[tempb].push_back(tempa);
        }
        node no;
        map<int,int> ma;
        no.ma = ma;
        no.last = 0;
        dfs(no);
        cout<<"Case #"<<te<<": "<<ans<<endl;
    }
    return 0;
}