#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ;te++){
        int n;
        cin>>n;
        map<long long ,long long> ma;
        for(int i = 0; i<n ; i++){
            long long temp;
            cin>>temp;
            ma[temp]++;
        }
        long long target = ma.begin()->first * ma.rbegin()->first;
        long long start = ma.begin()->first;
        if(start == 1){
            cout<<-1<<endl;
            continue;
        }
        int flag2 = 1;
        for(long long i = 2; i<= (long long)sqrt(target);i++){
            if(target % i == 0){
                if(ma[i] >0 && ma[target / i] > 0){
                    ma[i]++;
                    ma[target/i]++;
                }else{
                    flag2 = 0;
                    break;
                }
            }
        }
        for(auto it =ma.begin();flag2 == 1 && it != ma.end();it++){
            if(it->second <2){
                flag2 = 0;
            }
        }
        if(flag2 == 1){
            cout<<target<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}