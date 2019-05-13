#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

struct node{
    int x;
    int y;
    bool operator < (struct node b) const{
        if(this->x == b.x){
            return this->y < b.y;
        }
        return this->x < b.x;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<struct node, int> ma;
    for(int i = 0; i<n ; i++){
        int x,y;
        cin>>x>>y;
        struct node temp;
        temp.x = x;
        temp.y = y;
        ma[temp]++;
    }
    int x0 = 100000;
    int last = 9999999;
    int count = 0;
    for(auto it = ma.begin();it != ma.end();it++){
        if(it->first.x == x0){
            continue;
        }else{
            x0 = it->first.x;
            if(it->first.y < last){
                last = it->first.y;
                count += it->second;
            }
        }
    }
    cout<<count;
    return 0;
}