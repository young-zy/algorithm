#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t  ;i++){
        string a;
        long n;
        cin>>n;
        cin>>a;
        for(long j = 0; j< a.length();j++){
            if(a[j] == 'E'){
                a[j] = 'S';
            }else{
                a[j] = 'E';
            }
        }
        cout<<"Case #"<<i+1<<": "<<a<<endl;
    }
    return 0;
}