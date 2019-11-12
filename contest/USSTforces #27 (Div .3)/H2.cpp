#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
 
using namespace std;
 
long long a[100005];
 
set<long long> se;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int flag = 0;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        se.insert(a[i]);
    }
    auto a = se.rbegin();
    auto b = ++se.rbegin();
    long long maxnum = *a;
    long long sec = *b;
    if(maxnum < sec*2){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}