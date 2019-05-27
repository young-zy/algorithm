#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[30005];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int w;
    cin>>w;
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long count = 0;
    int flag = 0;
    int start = 0;
    int left = 0; 
    int right = n-1;
    while(left <= right){
        if(a[left] + a[right] <= w){
            count++;
            left++;
            right--;
        }else{
            right--;
            count++;
        }   
    }
    cout<<count;
    return 0;
}