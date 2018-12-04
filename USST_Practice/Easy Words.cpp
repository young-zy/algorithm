#include<bits/stdc++.h>

using namespace std;

int isPrime(int a);

int main(){
    string temp;
    cin>>temp;
    map<char,int> m;
    for(int i = 0;temp[i]!='\0';i++){
        if(m[temp[i]] == 0){
            m[temp[i]] = 1;
        }else{
            m[temp[i]]++;
        }
    } 
    map<char,int>::iterator it,itmin,itmax;
    itmin = m.begin();
    itmax = m.begin();
    for(it = m.begin();it!=m.end();it++){
        if(it->second > itmax -> second){
            itmax = it;
        }
        if(it->second < itmin -> second){
            itmin = it;
        }
    }
    int result = itmax -> second - itmin -> second;
    if(isPrime(result)){
        printf("Lucky Word\n%d",result);
    }else{
        printf("No Answer\n0");
    }
    return 0;
}

int isPrime(int a){
    if(a == 2){
        return 1;
    }
    if(a % 2 == 0){
        return 0;
    }
    if(a == 1){
        return 0;
    }
    for(int i = 3; i<= sqrt(a);i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}