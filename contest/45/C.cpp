#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int a[100];

int n,m;

int count2 = 0;
int count3 = 0;

void dfs(int index,int last){
    if(last == 2){
        a[index] = 3;
        last = 3;
        count3++;
    }else{
        a[index] = 2;
        last = 2;
        count2++;
    }
    if(index > m && a[index-m] == 0){
        dfs(index-m,last);
    }
    if(index % m != 1 && a[index -1] == 0){
        dfs(index-1,last);
    }
    if(index % m != 0 && a[index +1] == 0){
        dfs(index+1,last);
    }
    if(index <= n*(m-1) && a[index + m] == 0){
        dfs(index+m,last);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i*m+j +1];
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            if(a[i*m+j + 1] == 0){
                dfs(i*m+j+1,3);
            }
        }
    }
    if(count2 == count3){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}