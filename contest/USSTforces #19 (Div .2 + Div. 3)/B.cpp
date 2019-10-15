#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

map<char,int> ma1,ma2;
queue<int> qu;

int main(){
    bool flag = true;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    for(int i = 0; i<n ; i++){
        ma1[s[i]]++;
        ma2[t[i]]++;
    }
    for(auto it:ma1){
        if(ma2[it.first] != it.second){
            flag = false;
            break;
        }
    }
    int count = 0;
    for(int i = 0; i<n ; i++){
        if(s[i] == t[i]){
            continue;
        }else{
            // for(int j = i;j<n;j++){
            //     if(s[i] == t[j]){
            //         i--;
            //         break;
            //     }
            //     count++;
            //     qu.push(j+1);
            //     swap(s[j],s[j+1]);
            //     cout<<s<<endl;
            // }
            for(int j = i+1;j<n;j++){
                if(s[j] == t[i]){
                    count += j-i;
                    for(int k = j-1;k>=i;k--){
                        swap(s[k],s[k+1]);
                        qu.push(k+1);
                    }
                    //cout<<s<<endl;
                    break;
                }
            }
        }
    }
    if(!flag){
        cout<<"-1";
    }else{
        cout<<count<<endl;
        while(!qu.empty()){
            cout<<qu.front()<<" ";
            qu.pop();
        }
    }
    return 0;
}