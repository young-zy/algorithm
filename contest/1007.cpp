#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n ; i++){
        cin>>a[n];
    }
    map<int , int> ma;
    for(int i = 0; i<n-1;i++){
        ma[a[i+1] - a[i]]++;
    }
    int num = -1;
    for(auto it = ma.begin();it!=ma.end();it++){
        if(it-> second > 3){
            num = it->second;
        }
    }
    if(num == -1){

    }else{
        
    }
    return 0;
}