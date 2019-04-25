#include<bits/stdc++.h>

using namespace std;

int a[500][500];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int res[n+1];
    int flag = 1;
    map<int,int> ma;
    for(int i = 0; i< n ; i++){
        for(int j = 0; j< m ;j++){
            scanf("%d",&a[i][j]);
            ma[a[i][j]]++;
        }
    }
    if(n == 1){
        int flag = 0;
        for(int i = 0; i< m ; i++){
            if(a[0][i] != 0){
                flag = 1;
                cout<<"TAK"<<endl<<i;
                return 0;
            }
        }
        cout<<"NIE";
        return 0;
    }
    memset(res,0,sizeof(res));
    int test = a[0][res[0]];
    for(int i = 1; i<n-1 ; i++){
        test ^= a[i][res[i]];
    }
    for(int j  = 0; j<m ; j++){
        if(test ^ a[n-1][j] != 0){
            res[n-1] = j;
            test ^= a[n-1][j];
            break;
        }
    }
    if(test == 0){
        cout<<"NIE";
    }else{
        cout<<"TAK"<<endl;
        for(int i = 0;i<n ; i++){
            cout<<res[i]+1<<" ";
        }
    }
    return 0;
}