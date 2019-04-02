#include<bits/stdc++.h>

using namespace std;

int isback(long a);
int isPrime(long a);


int main(){
    long a,b;
    cin>>a>>b;
    for(long i = a ; i<=b;i++){
        if(isback(i) && isPrime(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}

int isback(long a){
    string s;
    while(a){
        s.append(1,(a % 10));
        a /= 10;
    }
    for(int i = 0; i< s.length()/2;i++){
        if(s[i] != s[s.length()-i-1]){
            return 0;
        }
    }
    return 1;
}

int isPrime(long a){
    if(a == 2 || a == 3){
        return 1;
    }else if(a == 1 || a % 2 == 0){
        return 0;
    }else{
        for(long i = 3; i<=sqrt(a);i++){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

long generate(){

}