#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int maxnum = max(n,m);
    map<int,int> ma;
    for(int i = 0; i<n;i++){
        int a;
        cin>>a;
        if(ma[a] == 0){
            ma[a]++;
        }
    }
    for(int i = 0; i<m;i++){
        int a;
        cin>>a;
        if(ma[a] == 1){
            ma[a]++;
        }
    }
    set<int> a;
    map<int,int>::iterator it = ma.begin();
    for(;it != ma.end();it++){
        if(it->second == 2){
            a.insert(it->first);
        }
    }
    if(a.size() == 0){
        cout<<"None";
    }else{
        for(set<int>::iterator it = a.begin();it != a.end();it++){
            printf("%d ",*it);
        }
    }
    return 0;
}