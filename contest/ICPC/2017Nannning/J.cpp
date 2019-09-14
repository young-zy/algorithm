#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[10005];
int b[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int counta[3];
    int countb[3];
    while(t--){
        int count[3];
        memset(count,0,sizeof(counta));
        int n;
        cin>>n;
        for(int i =0 ; i<n ; i++){
            cin>>a[i];
            a[i] %= 3;
            count[a[i]]++;
        }
        for(int i = 0; i<n ; i++){
            cin>>b[i];
            b[i] %= 3;
            count[b[i]]++;
        }
        if(count[0] > n || (count[0] < 2&&count[1]&&count[2])){
            cout<<"NO"<<endl;
            continue;
        }
        if(count[1] ==0 || count[2] == 0){
            cout<<"YES"<<endl;
            continue;
        }
        if(count[0] == 2 && !(count[1]%2) && !(count[2]%2)){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}