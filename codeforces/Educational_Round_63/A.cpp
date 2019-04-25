#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin>>n;
    string s;
    cin>>s;
    int flag = 0;
    for(long i = 0; i<s.length()-1;i++){
        if(s[i] > s[i+1]){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<"NO";
    }
    return 0;
}