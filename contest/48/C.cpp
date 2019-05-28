#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n-1;i++){
        cin>>a[i];
    }
    int b,c;
    cin>>b>>c;
    long sum = 0;
    if(b > c){
        int temp = b;
        b = c;
        c = temp;
    }
    for(int i = b-1;i<c-1;i++){
        sum += a[i];
    }
    cout<<sum;
    return 0;
}