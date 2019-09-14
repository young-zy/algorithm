#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[105];
int b[105];

map<int ,int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        ma[a[i]]++;
    }
    int m;
    cin>>m;
    for(int i = 0; i<m;i++){
        cin>>b[i];
        ma[b[i]]++;
    }
    long long count = 0;
    int flag = 0;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            if(ma[a[i]+b[j]]){

            }else{
                cout<<a[i]<<" "<<b[j];
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
   
    return 0;
}