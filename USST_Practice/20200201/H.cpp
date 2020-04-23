#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

char ch[100][100];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    string msg;
    for(int i = 0; i<n ; i++){
        cin>>msg;
        memset(ch, 0 ,sizeof(ch));
        int size = ceil( sqrt(msg.length()) );
        for(int j = 0 ; j< size ;j++){
            for(int k = 0; k< size;k++){
                ch[j][k] = msg[j*size+k];
            }
        }
        string res;
        for(int k = 0 ; k< size ;k++){
            for(int j = size-1; j >=0;j--){
                if(res.size() >= msg.size()){
                    break;
                }
                if(ch[j][k] == 0){
                    continue;
                }
                res.append(1, ch[j][k]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}