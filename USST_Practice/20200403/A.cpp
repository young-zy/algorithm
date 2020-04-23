#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long y,m,d;
    cin>>y>>m>>d;
    int a[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int flag = 0;
    if(y % 4 == 0){
        if(y % 100 == 0 && y % 400 != 0){
            flag = 0;
        }else{
            flag = 1;
        }
    }
    int day = 0;
    for(int i = 1; i < m;i++){
        day += a[i];
    }
    if(m > 2 && flag){
        day++;
    }
    day += d;
    cout<<day;
    return 0;
}