#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t; te++){
        int n,m;
        cin>>n>>m;
        string a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        int num = 0;
        int state = 0;
        num = b[0] - a[0];
        for(int i = 0; i< m;i++){
            c[i] -= num;
            if(c[i] < 'A'){
                c[i]+= 26;
            }
            if(c[i] > 'Z'){
                c[i] -= 26;
            }
        }
        cout<<"Case #"<<te+1<<": "<<c<<endl;
    }
    return 0;
}