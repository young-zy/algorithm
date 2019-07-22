#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

char ch[305][305];

long long a[305][305];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ;te++){
        int n,m;
        cin>>n>>m;
        for(int i = 0; i <n ; i++){
            for(int j = 0; j<m ; j++){
                cin>>ch[i][j];
                if(ch[i][j] == '.'){
                    a[i][j] = 1;
                }else{
                    a[i][j] = 0;
                }
            }
        }
        long long maxnum = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(a[i][j] == 1){
                    if(i>0 && j > 0){
                        a[i][j] = min(min(a[i-1][j-1],a[i][j-1]),a[i-1][j])+1;
                    }
                }
                maxnum = max(maxnum,a[i][j]*a[i][j]);
            }
        }
        cout<<maxnum<<endl;
    }
    return 0;
}