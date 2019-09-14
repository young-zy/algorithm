#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005];

struct node{
    int a,index;
    bool operator < (node n){
        return this->a < n.a;
    }
};

bool cmp(node n1,node n2){
    return n1.index < n2.index;
}

node no[100005];

deque<node> dq;
deque<int> ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    for(int i= 0; i<n ; i++){
        cin>>no[i].a;
        no[i].index = i;
    }
    sort(no,no+n);
    int target = 0;
    int i;
    for(i =0; i<n ; i++){
        if(no[i].a <= k){
            k -= no[i].a;
        }else{
            target = i;
            break;
        }
    }
    if(i == n){
        cout<<"-1";
        return 0;
    }
    sort(no+target,no+n,cmp);
    for(int i = target; i<n ; i++){
        dq.push_back(no[i]);
    }
    while(k > 0){
        k--;
        ans.push_back(dq.front().index);
        if(dq.front().a > 0){
            node temp = dq.front();
            temp.a--;
            dq.push_back(temp);
        }
        dq.pop_front();
        if(ans.size()+target>n){
            ans.pop_front();
        }
    }
    while (!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop_front();
    }
    
    return 0;
}