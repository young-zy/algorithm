#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 10000


using namespace std;

struct segtree{
    int n,cnt[Maxn],len[Maxn];
    segtree(int t):n(t){
        for(int i = 1; i<= t;i++){
            cnt[i] = len[i] = 0;
        }
    }
    //l0,r0为节点范围
    //l,r 为线段端点

    void update(int t, int l, int r);                   //更新
    void inc_seg(int t, int l0,int r0,int l, int r);    //
    void dec_seg(int t,int l0,int r0,int l,int r);      //用于加入边
    int seg_len(int t,int l0,int r0,int l, int r);      //求长度

    void update(int t, int l, int r){
        if( cnt[t] || r - l == 1){
            len[t] = length( l, r);
        }else{
            len[t] = len[t+1] + len[t + t +1];
        }
    }

};

int length(int l, int r){
    return r-l;
}



int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    return 0;
}