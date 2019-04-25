//线段树

#include<bits/stdc++.h>
#define endl "\n"

#define maxn 200000

using namespace std;

int a[2000005];



int tree[maxn << 2];
int tag[maxn << 2];

int n = 0;

int push_up(int p){
    tree[p] = __gcd(tree[p<<1+1],tree[p<<1+2]);
}

void build_tree(int l, int r,int p){
    if(l == r){
        tree[p] = a[l];
    }else{
        int mid = (l + r) >>1;
        build_tree(l,mid,p<<1+1);
        build_tree(mid+1,r,p<<1+2);
        push_up(p);
    }
}

void update(int il,int ir,int l, int r,int p){
    if(il <= l && ir <=r){

    }
}



void push_down(int p, int l, int r){
    int mid = (l + r) >> 1;

}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n; i ++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i = 0; i< q; i++){
        int flag,l,r;
        cin>>flag>>l>>r;
        if(flag == 0){

        }else{

        }
    }
    return 0;
}