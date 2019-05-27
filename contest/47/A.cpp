#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t;
    cin>>t;
    for(int i = 0; i<t;i++){
        string a,b;
        cin>>a>>b;
        int count = 0;
        if(a[0] == '-'){
            a.erase(0,1);
            count++;
        }
        if(b[0] == '-'){
            b.erase(0,1);
            count++;
        }
        if(a == "0" && b == "0"){
            cout<<"true"<<endl;
            continue;
        }
        if(count == 1 && a == b){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}