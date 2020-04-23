#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int n,m;

long long a[1000005];

long long sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b;
    long long res = 0;
    for(int i = 0; i<m ; i++){
        cin>>b;
        int l = 0;
        int r = n-1;
        int last_possible = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            if(a[mid] < b){
                last_possible = a[mid];
                l = mid+1;
            }else if(a[mid] == b){
                last_possible = a[mid];
                break;
            }else{
                r = mid-1;
            }
        }
        sum += b - last_possible;
    }
    cout<<sum;
    return 0;
}