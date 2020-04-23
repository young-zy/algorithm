#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[200005];

int findroot(int c){
    if(a[c] == -1){
        return c;
    }else{
        return a[c] = findroot(a[c]);
    }
}

void merge(int b, int c){
    c = findroot(c);
    b = findroot(b);
    if(c == b){
        return;
    }else{
        if(b<c){
            swap(b,c);
        }
        a[b] = c;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    for(int i = 0; i< m;i++){
        int b,c;
        cin>>b>>c;
        merge(b,c);
    }
    int count = 0;
    for(int i = 2 ;i<=n; i++){
        if(findroot(a[i]) != 1){
            cout<<i<<endl;
            count++;
        }
    }
    if(count == 0){
        cout<<"Connected";
    }
    return 0;
}