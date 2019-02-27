#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i<t ; i++){
        long n;
        cin>>n;
        long num = n/2;
        if(n % 2 != 0){
            num++;
        }
        string a;
        cin>>a;
        long sum = 0;
        long max = 0;
        for(long j = 0; j<num ;j++){
            sum += a[j] - 48;
        }
        max = sum;
        for(int j = 0 ;j < n/2;j++){
            sum-=a[j] - 48;
            sum+=a[j+num] - 48;
            if(sum > max){
                max = sum;
            }
        }
        cout<<"Case #"<<i+1<<": "<<max<<endl;
    }
    return 0;
}