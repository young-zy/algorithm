#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

#define int long long

using namespace std;

map<long long,long long> ma;

int a[100005];

map<long long,long long> start;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    for(long long i = 1; i<=n ; i++){
        cin>>a[i];
        ma[a[i]]++;
    }
    sort(a+1,a+n+1,less<int>());
    int index = 1;
    for(auto it:ma){
        start[it.first] = index;
        index += it.second*n;
    }
    long long time = k/n;
    long long num = k%n;
    time++;
    if(num == 0){
        time--;
        num = n;
    }
    if(ma[a[time]] > 1){
        k-=start[a[time]];
        k++;
        long long newtime = k /ma[a[time]];
        long long newnum = k%ma[a[time]];
        newtime++;
        if(newnum == 0){
            newtime--;
            newnum = ma[a[time]];
        }
        num = newtime;
    }
    cout<<a[time]<<" "<<a[num];
    return 0;
}