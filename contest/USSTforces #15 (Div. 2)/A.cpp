#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    int a,b;
    bool operator < (struct node no) const{
        return a<no.a;
    }
};

map<node, int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,m;
    cin>>a>>m;
    int flag = 1;
    while(1){
        struct node no;
        no.a = a % m;
        a += a%m;
        if(a % m == 0){
            break;
        }
        no.b = a % m;
        if(ma[no]){
            flag = 0;
            break;
        }else{
            ma[no]++;
        }
        a %= m;
    }
    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}