#include<bits/stdc++.h>

using namespace std;

long int_pow(int a,int b){
    long res = 1;
    for(int i = 0; i< b ; i++){
        res *= a;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t ; i++){
        long n;
        cin>>n;
        long a,b;
        long temp = n;
        long res = 0;
        int count = 0;
        while(temp){
            if(temp % 10 == 4){
                res += int_pow(10,count);
            }
            temp /= 10;
            count++;
        }
        cout<<"Case #"<<i+1<<": "<<res<<" "<<n-res<<endl;
    }
    return 0;
}