#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te< t ;te++){
        string a,b,c;
        cin>>a>>b>>c;
        int n = a.length();
        int flag = 1;
        int count = 0;
        int samecount = 0;
        for(int i = 0; i<n ; i++){
            if(a[i] == c[i] || b[i] == c[i]){
                continue;
            }else{
                flag = 0;
            }
        }
        if(flag == 0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}