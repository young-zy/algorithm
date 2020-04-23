#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    string temp;
    string pattern = "Simon says ";
    int flag;
    getchar();
    for( int i = 0 ; i < n  ; i++ ){
        flag = 1;
        getline(cin, temp);
        if(temp.length() < pattern.length() ){
            continue;
        }
        for(int j = 0; j < pattern.size(); j++){
            if( temp[j] != pattern[j] ){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<temp.substr(11)<<endl;
        }
    }
    return 0;
}