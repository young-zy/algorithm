#include<bits/stdc++.h>

using namespace std;


struct node{
    int height;
    int flag;
};

struct node a[100005];
struct node b[100005];

bool cmp(struct node a,struct node b){
    if(a.flag == b.flag){
        return a.height>b.height;
    }else{
        return a.flag > b.flag;
    }
}

int main(){
    long t;
    cin>>t;
    for(long te = 0; te<t;te++){
        long n,m;
        cin>>n>>m;
        for(long i = 0; i< n ; i++){
            cin>>a[i].height;
        }
        for(long i = 0 ;i< m ; i++){
            cin>>b[i].height;
        }
        for(long i = 0; i< n; i++){
            cin>>a[i].flag;
        }
        
        for(long i = 0; i< m; i++){
            cin>>b[i].flag;
        }
        sort(a,a+n,cmp);
        sort(b,b+m,cmp);
        for(long i = 0; i< n &&a[i].flag == 1; i++){
            for(long j = m-1;j>=0 && b[j].flag == 0;j--){

            }
        }

    }
    

    return 0;
}