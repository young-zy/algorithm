#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    string color;
    int num;
    bool operator < (node n) const{
        return this->num > n.num;
    }
}no[20];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    for(int ti = 0; ti < t; ti++){
        int n;
        cin>>n;
        int a;
        for(int  i = 0; i<n ; i++){
            cin>>no[i].color>>no[i].num;
        }
        sort(no,no+n);
        for(int i = 0; i<n ; i++){
            cout<<no[i].color;
            if(i != n-1){
                cout<<" ";
            }
        }
        if(t != ti-1){
            cout<<endl;
        }
    }
    return 0;
}