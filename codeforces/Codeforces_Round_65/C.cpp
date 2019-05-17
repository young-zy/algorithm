#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

#define maxn 50005

using namespace std;

//å¹¶æŸ¥é›†

int se[maxn],num[maxn];
int is_destroyed[maxn];

int find_root(int a){
    int res = a;
    while(se[res] != -1){
        res = se[res];
    }
    return res;
}

void merge(int a,int b){
    int roota = find_root(a);
    int rootb = find_root(b);
    // if(is_destroyed[a] || is_destroyed[b]){
    //     return;                             //has been destroyed
    if(roota == rootb){
        return;                             //already in same group
    }else{
        if(num[roota] <= num[rootb]){
            se[roota] = rootb;
            num[rootb] += num[roota]; 
        }else{
            se[rootb] = roota;
            num[roota] += num[rootb]; 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(is_destroyed,0,sizeof(is_destroyed)); //set initial state
    memset(se,-1,sizeof(se));
    for(int i = 0; i< maxn;i++){
        num[i] = 1;
    }
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<m;i++){
        int op;
        cin>>op;
        if(op == 1){
            int x,y;
            cin>>x>>y;
            merge(x,y);
        }else if(op == 2){
            int x;
            cin>>x;
            if(is_destroyed[x] == 0){
                is_destroyed[x] = 1;
                num[find_root(x)]--;
            }
        }else{
            int x;
            cin>>x;
            cout<<num[find_root(x)]<<endl;
        }
    }
    return 0;
}