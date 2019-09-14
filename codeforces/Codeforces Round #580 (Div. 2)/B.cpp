#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[100005];
int _count[3] = {0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long cost = 0;
    int flag = 0;
    long long ans = 0;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i = 0; i<n ; i++){
        if(a[i] == 0 && flag == 0){
            _count[flag] = i;
            flag++;
        }else if(a[i] >= 1 && flag != 2){
            if(flag == 0){
                _count[0] = i-_count[0];
            }else{
                _count[1] = i-_count[0];
            }
            flag = 2;
        }
        if(flag == 0){
            ans += -(a[i]+1);
        }else if(flag == 1){

        }else{
            ans += a[i]-1;
        }
    }
    if(flag == 0){
        _count[0] = n;
    }else if(flag == 1){
        _count[1] = n-_count[0];
    }
    _count[2] = n-_count[1]-_count[0];
    if(_count[0] % 2){
        if(_count[1] == 0){
            ans += 2;
        }else{
            ans += 1;
            _count[1]--;
        }
        ans+=_count[1];
    }else{
        ans += _count[1];
    }
    cout<<ans;
    return 0;
}