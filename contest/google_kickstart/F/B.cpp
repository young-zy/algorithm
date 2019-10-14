#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    unordered_map<int,int> uma;
};
node no[50005];
//unordered_map<int,int> whma;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te= 1; te <=t;te++){
        int n,s;
        cin>>n>>s;
        int c;
        int temp;
        for(int i = 0; i<n ; i++){
            cin>>c;
            no[i].uma.clear();
            for(int j = 0; j< c;j++){
                cin>>temp;
                no[i].uma[temp]++;
                //whma[temp]++;
            }
        }
        long long ans = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(i == j){
                    continue;
                }
                for(auto it:no[i].uma){
                    if(!it.second){
                        continue;
                    }
                    if(no[j].uma[it.first]){
                        continue;
                    }else{
                        ans++;
                        break;
                    }
                }
            }
        }

        cout<<"Case #"<<te<<": "<<ans<<endl;
    }
    return 0;
}