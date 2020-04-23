#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[100005];
int b[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 0; i<n ; i++){
            cin>>a[i];
        }
        for(int i = 0; i<n ; i++){
            cin>>b[i];
        }
        int last = 0;
        int flag = 1;
        int flag2 = 1;
        for(int i = 0; i<n ; i++){
            int c = b[i] - a[i];
            if(c != last){
                if(flag2){
                    flag2 = 0;
                    last = c;
                }else{
                    if(c == 0){
                        last = 0;
                        continue;
                    }
                    flag = 0;
                    break;
                }
            }else{
                continue;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}