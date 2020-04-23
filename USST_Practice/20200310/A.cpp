#include<iostream>
#include<math.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int isPrime(int a){
    if(a == 2 || a == 3){
        return 1;
    }else if(a % 2 == 0 || a <= 1){
        return 0;
    }else{
        for(int i = 3 ; i*i <= a; i += 2){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,r;
    cin>>l>>r;
    int count = 0;
    for(int i = 0; i< 729; i++){
        int temp = i;
        int sum = 0;
        while(temp){
            sum += temp % 3;
            temp /=3;
        }
        if(isPrime(sum) || (sum >=l && sum <=r) ){
            count++;
        }
    }
    cout<<count;
    return 0;
}