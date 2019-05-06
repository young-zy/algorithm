#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[200005];

map<int ,int> ma;

int c[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i< n; i++){
        cin>>a[i];
    }
    int temp;
    ma[1] = 0;
    for(int i = 0; i< n; i++){
        cin>>temp;
        ma[temp]++;
    }

    for(int i = 0; i<n; i++){
        int minnum = n;
        int num = 0;
        for(auto it = ma.begin();it != ma.end();it++){
            // if(it->second == 0){
            //     it = ma.erase(it);
            //     it--;
            //     continue;
            // }
            if(it->second > 0 && (a[i] + it->first) % n < minnum){
                minnum = (a[i] + it->first) % n;
                num = it->first;
                if(minnum == 0){
                    break;
                }
            }
        }
        ma[num]--;
        c[i] = minnum;
    }
    for(int i = 0; i< n; i++){
        cout<<c[i]<<" ";
    }
    return 0;
}