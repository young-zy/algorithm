#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    string a[n];
    string b[n];
    int count = 0;
    map<string,int> mp;
    for(int i = 0; i< n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    //for(map<string,int>::iterator it);
    
    // for(int i = 0; i<n;i++){
    //     cout<<b[i]<<endl;
    // }
    cout<<count;
    //system("pause");
    return 0;
}