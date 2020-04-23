#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int a[3005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int temp;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    long long count = 0;
    for(int i = n-2; i>=0;i--){
        if(a[i] > a[i+1]){
            int num = ceil((double)a[i]/a[i+1]);
            int avg = floor((double)a[i]/num);
            count += num-1;
            a[i] = avg;            
        }
    }
    cout<<count;
    return 0;
}