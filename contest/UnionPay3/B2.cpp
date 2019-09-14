#include<bits/stdc++.h>
using namespace std;
#define IOS  std::ios::sync_with_stdio(false); std::cin.tie(0);
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef int itn;
ll n,m,p;

ll gcd(int x, int y){
    int MAX = max(x, y);
    int MIN = min(x, y);
    return MAX % MIN == 0? MIN : gcd(MIN, MAX % MIN);
 }
 
ll lcm(int x, int y){
    return x * y / __gcd(x, y);
}

int cnt(){ 
    ll num=0;
    ll count=0;
//  ll k=min(sqrt(n),a);
    ll k=sqrt(p);
    for(ll i=2;i<=k;i++){
        if(p%i==0){
            ll q=(p/i);
            if(i<=n&&q<=m) {
                count+=(((n/i)-(n/p))*((m/q)-(m/p)));
//              cout<<i<<" "<<count<<endl;
            }
            if(i<=m&&q<=n){
                count+=(((n/q)-(n/p))*((m/i)-(m/p)));
//              cout<<i<<" "<<count<<endl;
            }
            count-=(min(n,m)/lcm(i,q));
            count+=(min(n,m)/p);
        }
    }
    if(n>=p&&m>=p){
        count+=((m/p)*n+(n/p)*m-(n/p)*(m/p));
//      cout<<1<<endl;
    }else if(n>=p){
        count+=(m*(n/p));
//      cout<<2<<endl;
    }else if(m>=p){
        count+=(n*(m/p));
//      cout<<3<<endl;
    }
    return count;
}

int main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        cout<<cnt()<<endl;   
    }
    return 0;
}