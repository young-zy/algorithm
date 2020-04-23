#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int a,b;
    for(int te = 0 ; te < t ; te++){
        cin>>a>>b;
        string as,bs;
        while(a){
            as.insert(0, 1, '0'+(a&1));
            a>>=1;
        }
        while(b){
            bs.insert(0, 1, '0'+(b&1));
            b>>=1;
        }
        for(int i = bs.length()-1; i>=0; i--){
            if(bs[i] == '0'){
                bs.erase(i);
            }else{
                break;
            }
        }
        if(as.find(bs) != string::npos){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}