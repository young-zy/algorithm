#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    int f[10];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string a;
    cin>>a;
    for(int i = 1; i<=9;i++){
        cin>>f[i];
    }
    int flag = 0;
    int index= 0;
    while(f[a[index]-'0'] <= a[index]-'0' && index <= a.length()){
        index++;
    }
    for(long i = index; i< a.length();i++){
        if(f[a[i]-'0'] >= a[i]-'0'){
            a[i] = f[a[i]-'0']+'0';
        }else{
            break;
        }
    }
    cout<<a;
    return 0;
}