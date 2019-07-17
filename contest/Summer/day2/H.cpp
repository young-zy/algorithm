#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int que[10000005];
int _head,_end;

int n,m,k;
long long p,q,r,MOD,maxrating,_count;

long long a[10000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k>>p>>q>>r>>MOD;
    for(int i = 1; i<=k ; i++){
        cin>>a[i];
    }
    for(int i = k+1; i<=n;i++){
        a[i] = (p*a[i-1]+q*i+r) % MOD;
    }
    maxrating = 0;      //初始化
    _count = 0;
    _head = 0;
    _end = 0;
    for(int i = 1; i<=n ; i++){
        if(_head < _end && que[_head] <= i-m){  //单调队列存储下标信息
            _head++;                            
        }
        while(_head < _end && a[que[_end-1]]<=a[i]){
            _end--;
        }
        que[_end] = i;
        _end++;
        if(i >= m ){
            maxrating += (a[que[_head]] ^ (i-m+1));
        }
    }
    _head = 0;
    _end = 0;
    for(int i = n; i>=1;i--){
        if(_head < _end && que[_head] >= i+m){  //单调队列存储下标信息
            _head++;                            
        }
        while(_head < _end && a[que[_end-1]]<=a[i]){
            _end--;
        }
        que[_end] = i;
        _end++;
        if(i <= n-m+1 ){
            _count += ((_end-_head) ^ i);
        }
    }
    cout<<maxrating<<" "<<_count;
    return 0;
}