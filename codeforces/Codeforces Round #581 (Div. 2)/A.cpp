#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    long long ans = 0;
    ans = (s.length()-1)/2+1;
    if((s.length()-1) % 2 == 0){
        int flag = 0;
        for(int i = 1;i<s.length();i++){
            if(s[i] == '1'){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            ans--;
        }
    }
    cout<<ans;
    return 0;
}