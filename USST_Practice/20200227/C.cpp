#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct node{
    int x,y;
    bool operator < (struct node no) const{
        if(y == no.y){
            return x < no.x;
        }
        return y < no.y;
    }

    node(int _x, int _y){
        x = _x;
        y = _y;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te< t;te++){
        int n;
        cin>>n;
        int x,y;
        string res;
        set<node> se;
        int maxx = 0;
        for(int i = 0; i<n ; i++){
            cin>>x>>y;
            se.insert(node(x,y));
        }
        int flag = 1;
        int curx = 0;
        int cury = 0;
        for( auto it = se.begin();it!= se.end();it++){
            if(it->x - curx < 0){
                flag = 0;
                break;
            }
            res.append( it->x - curx , 'R' );
            curx = it->x;
            res.append( it->y - cury ,'U');
            cury = it->y;           
        }
        // for(int i = 0; i <= maxx; i++){
        //     if(i != maxx){
        //         if(*se[i].rbegin() > *se[i+1].begin()){
        //             flag = 0;
        //             break;
        //         }
        //     }
        //     if(se[i].size() != 0){
        //         res.append(*se[i].rbegin() - cur+1,'R');
        //     }
        //     if(i != maxx){
        //         res.append(1,'U');
        //     }
        //     cout<<res<<endl;
            
        // }
        if(flag == 0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<res<<endl;
        }
        
    }
    return 0;
}