#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

map<int, int> ma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp;
    for(int i = 0; i<n ; i++){
        cin>>temp;
        ma[temp]++;
    }
    int res = 0;
    auto it1 = ma.begin();
    auto it2 = ma.begin();
    while(it2 != ma.end()){
        if(it1->second == 0){
            it1++;
            continue;       
        }
        if(it2->first < it1->first *2){
            it2++;
            continue;
        }
        if(it2->second == 0){
            it2++;
            continue;
        }
        it1->second--;
        it2->second--;
        res++;
    }
    for (auto it:ma){
        res += it.second;
    }
    cout<<res;
    return 0;
}