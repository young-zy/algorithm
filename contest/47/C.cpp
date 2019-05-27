#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

// T<=10, n<=1e5

int a[100005];
int length[100005];
set<int> se[100005];

int query(int last,int a){
    if(se[a].size() == 1){
        return 1;
    }
    int len = 0;
    if(*se[a].begin() != last){
        last = a;
        a = *se[a].begin();
    }else{
        last = a;
        a = *se[a].rbegin();
    }
    return query(last,a)+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int j = 0; j<t;j++){
        int n,r;
        cin>>n>>r;
        memset(a,0,sizeof(a));
        for(int i = 0; i<=n ; i++){
            se[i].clear();
        }
        for(int i = 0; i< n-1;i++){
            int u,v;
            cin>>u>>v;
            se[u].insert(v);
            se[v].insert(u);
        }
        // while(se[i].size() > 1 || i == r){
        //     if(*se[i].begin() != last){
        //         last = i;
        //         i = *se[i].begin();
        //         length++;
        //     }else{
        //         last = i;
        //         i = *se[i].rbegin();
        //         length++;
        //     }
        // }
        // if(se[r].size() == 1){
        //     int length = query(-1,*se[r].begin());
        //     if(length % 2){
        //         cout<<"Haruhi go first."<<endl;
        //     }else{
        //         cout<<"Haruhi go secondary."<<endl;
        //     }
        // }else{
        //     int length1 = query(-1,*se[r].begin());
        //     int length2 = query(-1,*se[r].rbegin());
        //     if(length1 % 2 == length2 % 2){
        //         if(length1 % 2){
        //             cout<<"Haruhi go first."<<endl;
        //         }else{
        //             cout<<"Haruhi go secondary."<<endl;
        //         }
        //     }else{
        //         cout<<"Haruhi go first."<<endl;
        //     }
        // }
        int begin,end;
        for(int i = 1; i<=n ; i++){
            if(se[i].size() == 1){
                begin = i;
            }
        }
        // for(int i = begin+1; i<=n;i++){
        //     if(se[i].size() == 1){
        //         end = i;
        //     }
        // }
        int i = begin;
        int last = -1;
        int length1 = 0;
        while(i != r){
            if(*se[i].begin() != last){
                last = i;
                i = *se[i].begin();
                length1++;
            }else{
                last = i;
                i = *se[i].rbegin();
                length1++;
            }
        }
        int length2 = n- length1 -1;
        if(length1 % 2 == length2 % 2){
            if(length1 % 2){
                cout<<"Haruhi go first."<<endl;
            }else{
                cout<<"Haruhi go secondary."<<endl;
            }
        }else{
            cout<<"Haruhi go first."<<endl;
        }
    }
    return 0;
}

/*
2
3 1
1 2
2 3
5 4
1 2
1 3
3 4
4 5
*/