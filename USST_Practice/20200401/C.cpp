#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[205],b[205];

int res[5][5] = {
    {0,-1,1,1,-1},
    {1,0,-1,1,-1},
    {-1,1,0,-1,1},
    {-1,-1,1,0,1},
    {1,1,-1,-1,0}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,na,nb;
    cin>>n>>na>>nb;
    for(int i = 0; i< na; i++){
        cin>>a[i];
    }
    for(int i = 0; i< nb; i++){
        cin>>b[i];
    }
    int resa = 0;
    int resb = 0;
    int i = 0,j = 0;
    while(n--){
        if(res[a[i]][b[j]] == 1){
            resa++;
        }else if(res[a[i]][b[j]] == -1){
            resb++;
        }
        i++;
        j++;
        if(i >= na){
            i = 0;
        }
        if(j >= nb){
            j = 0;
        }
    }
    cout<<resa<<" "<<resb;
    return 0;
}