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
    int ch[26];
    int flag;
    string res;
    getchar();
    for(int i =0 ; i<n ; i++){
        flag = 1;
        res = "";
        getline(cin, temp);
        memset(ch, 0, sizeof(ch));
        for(int i = 0; i<temp.length() ; i++){
            if(temp[i] >= 'A' && temp[i] <= 'Z'){
                ch[temp[i] - 'A']++;
            }else if(temp[i] >= 'a' && temp[i] <= 'z'){
                ch[temp[i] - 'a']++;
            }
        }

        for(int i = 0; i<26 ; i++){
            if(ch[i] == 0){
                flag = 0;
                res.append(1, 'a'+i);
            }
        }
        if(flag == 0){
            cout<<"missing "<<res<<endl;
        }else{
            cout<<"pangram"<<endl;
        }
    }
    return 0;
}