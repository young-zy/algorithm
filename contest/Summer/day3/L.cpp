#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

map<int,int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int count =  0;
    int ans = 0;
    for(int i = 0; i<n ; i ++){
        int temp;
        cin>>temp;
        ma[temp]++;
        if(ma[temp] == 2){
            count++;
        }
        if(count == 2 || ma[temp] == 4){
            ans++;
            count = 0;
            ma.clear();
        }
    }
    cout<<ans;
    return 0;
}