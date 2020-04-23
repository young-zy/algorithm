#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int aa[10005][4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a,b,g,k;
    for(int i =0 ; i<n ; i++){
        for(int j = 0; j< 4; j++){
            cin>>aa[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    int res = -1;
    for(int i = 0; i<n;i++){
        if(x>=aa[i][0] && x<=aa[i][0]+ aa[i][2] && y>= aa[i][1] && y <= aa[i][1]+ aa[i][3]){
            res = i+1;
        }
    }
    cout<<res;
    return 0;
}