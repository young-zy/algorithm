#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    int m;
    cin>>n>>m>>k;
    for(int i = 0; i<m; i++){
        cin>>a[i];
    }
    long long num = 0; 
    long long offset = k;
    long long nums = 0;
    while(1){
        if(offset > n+k){
            break;
        }
        long long count = 0;
        for(long long i = num; i< m; i++){
            if(a[i] <= offset){
                count++;
                num++;
            }
            if(a[i] > offset){
                break;
            }
        }
        offset += count;
        if(count == 0){
            nums--;
            offset += k;
        }
        nums++;
    }
    cout<<nums;
    return 0;
}