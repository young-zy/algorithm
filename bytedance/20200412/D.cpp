#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

const int maxn = 100005;
// const int maxn = 100;

int a[maxn];
long long res[maxn];
long long res2[maxn];



struct node{
    int index,val;
    bool operator < (node no){
        return val < no.val;
    }
};


node no[100005];
int flag[100005];
int n;

void rec(int start, int end){
    if(start > end){
        return;
    }
    if(start == end){
        res[start] = 1;
    }
    for(int i = n-1; i>=0; i--){
        if(no[i].index >=start &&no[i].index <=end){
            res[no[i].index] = end-start;
            rec(start,no[i].index-1);
            rec(no[i].index+1,end);
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        memset(flag,0,sizeof(flag));
        
        cin>>n;
        int l = 0;
        int r = 0;
        for(int i =0;i<n;i++){
            no[i].index = i;
            cin>>no[i].val;
        }
        sort(no,no+n);
        rec(0,n-1);
        for(int i = 0; i<n ; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}