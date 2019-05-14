#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,n1;
    int arr[1000];

    cin>>n;
    n1 = 2*n-1;
    for(int i = 0; i<n1 ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n1);

    int s1 = 0;
    for(int i = 0; i<n ; i++){
        s1+=arr[i];
    }
    if(s1<0){
        for(int i = 0;i < n ;i++){
            arr[i] *= -1;
        }
    }

    long s2 = 0;
    for(int i = 0; i<n1;i++){
        s2+=arr[i];
    }
    cout<<s2;
    return 0;
}