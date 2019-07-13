#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define maxn 100005
 
using namespace std;
 
struct base{
    int d;
    int g;
    bool operator < (struct base b){
        return this->d < b.d;
    }
};
 
int a[maxn];
struct base ba[maxn];
long long res[maxn];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s,b;
    cin>>s>>b;
    for(int i = 0; i<s ; i++){
        cin>>a[i];
    }
    memset(res,0,sizeof(res));
    for(int i = 0 ; i<b ; i++){
        cin>>ba[i].d>>ba[i].g;
    }
    sort(ba,ba+b);
    for(int i = 0; i<s;i++){
        for(int j = 0; j<b;j++){
            if(a[i] >= ba[j].d){
                res[i] += ba[j].g;
            }else{
                break;
            }
        }
    }
    for(int i = 0; i<s ; i++){
        cout<<res[i]<<" ";
    }
    return 0;
}