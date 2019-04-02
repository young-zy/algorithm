#include<bits/stdc++.h>

using namespace std;

string a[100005];

bool cmp(string &b, string &c){
    string t = b + c;
    string t1 = c + b;
    if(t > t1){
        return true;
    }else{
        return false;
    }
}

// bool cmp(string b, string c){
//     return b+c>c+b;
// }

int main(){
    long n;
    cin>>n;
    for(long i =0 ;i < n ; i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(long i = 0; i< n ; i++){
        cout<<a[i];
    }
    return 0;
}