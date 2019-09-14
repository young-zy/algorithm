#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t;
    cin>>t;
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(t.length() > s.length()){
            if(t.find(s) != string::npos){
                cout<<"my child!"<<endl;
            }else{
                cout<<"oh, child!"<<endl;
            }
        }else if(t.length() < s.length()){
            if(s.find(t) != string::npos){
                cout<<"my teacher!"<<endl;
            }else{
                cout<<"senior!"<<endl;
            }
        }else{
            if(s == t){
                cout<<"jntm!"<<endl;
            }else{
                cout<<"friend!"<<endl;
            }
        }
    }
    return 0;
}