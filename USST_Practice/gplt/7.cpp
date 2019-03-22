#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    char c;
    cin>>n>>c;
    for(int i =1;i <= (double)n/2+0.5 ;i++){
        for(int j = 0; j< n ;j++){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}