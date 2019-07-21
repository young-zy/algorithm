#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100][100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    while(cin>>n>>m){
        if(n == 0 && m == 0){
            break;
        }
        for(int i = 0 ;i <n ; i++){
            for(int j = 0 ;j<m;j++){
                cin>>a[i][j];
            }
        }
        
    }
    cin>>n>>m;
    
    return 0;
}