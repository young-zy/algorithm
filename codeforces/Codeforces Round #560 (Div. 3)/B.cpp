#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[200005];

map<int , int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        ma[a[i]]++;
    }
    int index = 1;
    long long count = 0;
    for(auto it = ma.begin(); it!= ma.end();it++){
        while(it->second > 0 && it->first >= index){
            count++;
            it->second--;
            index++;
        }
    }
    cout << count;
    return 0;
}