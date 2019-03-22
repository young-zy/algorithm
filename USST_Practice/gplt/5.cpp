#include<bits/stdc++.h>

using namespace std;

long a[10];

int main(){
    int n;
    a[0] = 1;
    for(int i =1 ;i < 10; i++){
        a[i] = a[i-1] * (i+1);
    }
    cin>>n;
    long sum = 0;
    for(int i =n-1 ;i >= 0 ;i--){
        sum += a[i];
    }
    cout<<sum;
    return 0;
}