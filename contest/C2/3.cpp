#include<bits/stdc++.h>

using namespace std;

int a[10001];

int main(){
    int n;
    cin>>n;
    for(int i =1 ;i <= 10000;i++){
        int temp = i;
        int sum = i;
        while(temp !=0){
            sum += temp % 10;
            temp/=10;
        }
        a[i] = sum;
        if(n == sum){
            cout<<i;
            return 0;
        }
    }
    cout<<"no";
    return 0;
}