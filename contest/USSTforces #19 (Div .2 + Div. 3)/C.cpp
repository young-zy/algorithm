#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

string s[100005];

// struct node{
//     string s;   //word
//     int a;      //cost
//     int index;
// } no[100005];

map<string ,int> ma;

int ro[100005][2];

int find_root(int a){
    if(ro[a][0] == -1){
        return a;
    }else{
        return ro[a][0] = find_root(ro[a][0]);
    }
}

int merge(int a,int b){
    if(find_root(a) == find_root(b)){
        return find_root(a);
    }
    if(ro[find_root(a)][1] < ro[find_root(b)][1]){
        ro[find_root(b)][0] = find_root(a);
        return find_root(b);
    }else{
        ro[find_root(a)][0] = find_root(b);
        return find_root(a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m;
    cin>>n>>k>>m;
    memset(ro,-1,sizeof(ro));
    string temps;
    for(int i = 1; i<=n ; i++){
        cin>>temps;
        ma[temps] = i;
    }
    for(int i = 1; i<=n ; i++){
        cin>>ro[i][1];
    }
    for(int i = 1; i<=k;i++){
        int x;
        cin>>x;
        int root = -1;
        int temp;
        for(int j = 0; j<x;j++){
            cin>>temp;
            if(j == 0){
                root = temp;
            }else{
                merge(root,temp);
            }
        }
    }
    long long count = 0;
    for(int i = 0; i<m ; i++){
        cin>>s[i];
        count += ro[find_root(ma[s[i]])][1];
    }
    cout<<count;
    return 0;
}