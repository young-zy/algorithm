#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

long long a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    for(int mi = 0 ;mi < m; mi++){
        int query = 0;
        cin>>query;
        int res = a[0];
        int l = 0;
        int r = n-1;
        long long mid;
        while( l<r ){
            mid = (l+r)>>1;
            if( a[mid] < query ){
                res = a[mid];
                l = mid + 1;
            }else if( a[mid] > query){
                r = mid - 1;
            }else{
                res = a[mid];
                break;
            }
        }
        if(fabs(query - a[mid]) > fabs(query - a[mid+1])){
            res = a[mid+1];
        }
        cout<<res<<endl;
    }   
    return 0;
}