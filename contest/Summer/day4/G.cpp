#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 200005
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

long long tree[200005 * 4];

void pushup(int tindex){
    tree[tindex] = max(tree[tindex<<1],tree[(tindex<<1)|1]); 
}

void build(int treeindex,int l,int r){
    if(l == r){
        tree[treeindex] = 0;
        return;
    }
    int m = (l+r)>>1;
    if(l<=m){
        build(treeindex<<1,l,m);
    } 
    if(m < r){
        build((treeindex<<1)|1,m+1,r);
    }
}

void modify(int treeindex,int l, int r, int index,long long y){
    if(l == r){
        tree[treeindex] = y;
        return;
    }
    int m = (l+r)>>1;
    if(index <= m){
        modify(treeindex << 1,l,m,index, y);
    }else{
        modify((treeindex << 1) | 1,m+1,r,index, y);
    }
    pushup(treeindex);
}

long long query(int treeindex,int l,int r,int ll,int rr){
    if(ll<=l && rr>=r){
        return tree[treeindex];
    }
    int m = (l+r)>>1;
    long long ans = -INF;
    if(ll <= m){
        ans = max(ans,query(((treeindex<<1)),l,m,ll,rr));
    }
    if(m < rr){
        ans = max(ans,query(((treeindex<<1)|1),m+1,r,ll,rr));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m,d;
    cin>>m>>d;
    long long length = 0;
    build(1,1,m);
    long long last = 0;
    for(int i = 0; i<m ; i++){
        char ch;
        int b;
        cin>>ch>>b;
        if(ch == 'Q'){
            cout<<(last = query(1,1,m,length-b+1,length))<<endl;
        }else{
            modify(1,1,m,++length,(last+b +d)%d);
        }
    }
    return 0;
}