#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s[3];
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    int a[3];
    for(int i = 0; i<3;i++){
        if(s[i] == "rock"){
            a[i] = 0;
        }else if(s[i] == "scissors"){
            a[i] = 1;
        }else{
            a[i] = 2;
        }
    }
    int res[3] = {0};
    for(int i = 0; i<3;i++){
        for(int j = 0; j<3;j++){
            if(i == j){
                continue;
            }
            if(a[i] - a[j] == 1){
                res[j]++;
            }else if(a[i] - a[j] == -1){
                res[i]++;
            }else if(a[i] - a[j] == 2){
                res[i]++;
            }else{
                res[j]++;
            }
        }
    }
    if(res[0] == res[1]){
        if(res[2] > res[1]){
            cout<<"S";
        }else{
            cout<<"?";
        }
    }else if(res[1] == res[2]){
        if(res[0] > res[1]){
            cout<<"F";
        }else{
            cout<<"?";
        }
    }else if(res[2] == res[0]){
        if(res[1] > res[2]){
            cout<<"M";
        }else{
            cout<<"?";
        }
    }else{
        cout<<"?";
    }
    return 0;
}