#include<bits/stdc++.h>

using namespace std;

struct node{
    int p;
    int m;
};

bool cmp(node a, node b){
    return a.p > b.p;
}

int main(){
    int v,n;
    while(1){
        scanf("%d",&v);
        if(v == 0){
            break;   
        }
        scanf("%d",&n);
        long res = 0;
        node no[n];
        for(int i =0 ; i< n;i++){
            scanf("%d %d",&no[i].p,&no[i].m);
        }
        sort(no,no+n,cmp);
        for(int i = 0; i < n;i++){
            if(v >= no[i].m){
                res += no[i].p * no[i].m;
                v -= no[i].m;
            }else{
                res += v * no[i].p;
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}