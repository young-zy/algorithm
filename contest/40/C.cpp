#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

struct node{
    char ch;
    int index;
};

bool cmp(struct node a,struct node b){
    if(a.ch == '?'){
        return false;
    }else if(b.ch == '?'){
        return true;
    }else{
        return a.ch < b.ch;
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,m;
    string a;
    string b;
    cin>>n>>m;
    cin>>a>>b;
    deque<struct node> dqa;
    deque<struct node> dqb;
    for(int i = 0; i<n ; i++){
        struct node temp;
        temp.ch = a[i];
        temp.index = i;
        dqa.push_back(temp);
    }
    for(int i = 0; i<m; i++){
        struct node temp;
        temp.ch = b[i];
        temp.index = i;
        dqb.push_back(temp);
    }
    sort(dqa.begin(),dqa.end(),cmp);
    sort(dqb.begin(),dqb.end(),cmp);
    int count  = 0;
    map<int,int> ma;
    while(!dqa.empty() && !dqb.empty()){
        if(dqa.front().ch == '?' || dqb.front().ch == '?'){
            count++;
            ma[dqa.front().index] = dqb.front().index;
            dqa.pop_front();
            dqb.pop_front();
        }else if(dqa.front().ch < dqb.front().ch){
            if(dqb.back().ch == '?'){
                count++;
                ma[dqa.front().index] = dqb.back().index;
                dqb.pop_back();
            }
            dqa.pop_front();
        }else if(dqa.front().ch == dqb.front().ch){
            count++;
            ma[dqa.front().index] = dqb.front().index;
            dqa.pop_front();
            dqb.pop_front();
        }else{
            if(dqa.back().ch == '?'){
                count++;
                ma[dqa.back().index] = dqb.front().index;
                dqa.pop_back();
            }
            dqb.pop_front();
            
        }
    }
    cout<<count<<endl;
    for(auto it = ma.begin();it != ma.end();it++){
        cout<<it->first+1<<" "<<it->second+1<<endl;
    }
    return 0;
}