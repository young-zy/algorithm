#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define maxn 100005

using namespace std;

string s;

struct node{
    int ch[26];
}no[maxn*4];

inline long long left_son(long long p){
    return p << 1;          //p*2
}

inline long long right_son(long long p){
    return p << 1 | 1;      //p * 2 + 1
}

inline void upward_update(long long p){         //向上更新
    for(int i = 0; i<26;i++){
        no[p].ch[i] = no[left_son(p)].ch[i] + no[right_son(p)].ch[i];
    }
}

inline void build(long long p, long long l,long long r){       //建树
    if(l == r){                                     //若左标记等于右标记，说明为叶子节点
        no[p].ch[s[l]-'a'] = 1;
        return;
    }
    long long mid = (l + r) >> 1;                   //计算中值
    build(left_son(p),l,mid);                       //建左子树
    build(right_son(p), mid+1,r);                   //建右子树
    upward_update(p);                               //更新节点p
}

inline void update(long long p,long long pos, long long l, long long r, char k){
    //l0,r0 为需要更改的区间范围
    //l,r   为当前所在的区间范围
    //no[p].ch[k-'a']++;
    long long mid = (l + r) >> 1;
    if(l == r){
        char ch = s[l];
        no[p].ch[ch-'a']--;
        no[p].ch[k-'a']++;
        s[l] = k;
        return;
    }
    if(pos <= mid){
        update(left_son(p),pos,l,mid,k);
    }
    if(pos > mid){
        update(right_son(p),pos,mid+1,r,k);
    }
    upward_update(p);
}

vector<int> query(long long l0,long long r0,long long l, long long r,long long p){
    vector<int> ans(26);
    long long mid = (l + r) >> 1;
    long long res = 0;
    if(l0 <= l && r0 >=r){
        vector<int> ans;
        for(int i = 0; i<26 ; i++){
            ans.push_back(no[p].ch[i]);
        }
        return ans;
    }
    if(l0 <= mid){
        vector<int> temp = query(l0,r0,l,mid,left_son(p));
        for(int i = 0; i<26; i++){
            ans[i] += temp[i];
        }
    }
    if(r0 > mid){
        vector<int> temp = query(l0,r0,mid+1,r,right_son(p));
        for(int i = 0; i<26; i++){
            ans[i] += temp[i];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    s.insert(0,1,'0');
    build(1,1,s.length()-1);
    int q;
    cin>>q;
    for(int qe = 0; qe<q;qe++){
        int sw,l,r;
        char c;
        cin>>sw;
        if(sw == 1){
            cin>>l>>c;
            //s[l] = c;
            update(1,l,1,s.length()-1,c);
            //cout<<s<<endl;
        }else{
            cin>>l>>r;
            vector<int> ve = query(l,r,1,s.length()-1,1);
            int count = 0;
            for(int i =0; i<26;i++){
                if(ve[i]){
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}