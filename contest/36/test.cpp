#include<bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    long i = 0;
    for(i = 0; i< min(a.length(),b.length());i++){
        if(a[i] > b [i]){
            return true;
        }else if(a[i] < b[i]){
            return false;
        }
    }
    if((i == a.length() || i == b.length() )&& a.length()!=b.length()){
        if(i == a.length()){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int main(){
    cout<<cmp("1","55554");
    return 0;
}

