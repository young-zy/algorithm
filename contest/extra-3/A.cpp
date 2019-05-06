#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[10] = {1,0,0,0,0,0,1,0,2,1};
    string b;
    cin>>b;
    int count = 0;
    for(int i = 0; i< b.length();i++){
        count += a[b[i] - '0'];
    }
    cout << count;
    return 0;
}