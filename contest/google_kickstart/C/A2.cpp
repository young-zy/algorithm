#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct Node{
    int x,y;
    bool operator < (Node b) const{
        if(this-> x == b.x){
            return this-> y == b.y;
        }
        return this-> x < b.x;
    }
};



int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    set<struct Node> se;
    int t;
    cin>>t;
    for(int te = 1; te <=t;te++){
        se.clear();
        int n,r,c,sr,sc;
        cin>>n>>r>>c>>sr>>sc;
        string a;
        cin>>a;
        static struct Node temp;
        temp.x = sr;
        temp.y = sc;


        cout<<"Case #"<<te<<": "<<sr<<" "<<sc<<endl;
    }
    
    return 0;
}