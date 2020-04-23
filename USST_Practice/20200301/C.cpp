#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    unordered_set<string> use;
    while(t--){
        string s;
        while(s == ""){
            getline(cin, s);
        }
        stringstream ss;
        ss<<s;
        string a,b,c;
        use.clear();
        while(a!= "what" &&b != "does" &&c != "the"){
            cin>>a>>b>>c;
            use.insert(c);
        }
        cin>>a>>b;
        string res,temp;
        while(!ss.eof()){
            ss>>temp;
            if(use.find(temp) == use.end()){
                res += temp+" ";
            }
        }
        res.erase(res.length()-1,1);
        cout<<res<<endl;
    }
    return 0;
}