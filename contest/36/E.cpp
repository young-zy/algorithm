#include<bits/stdc++.h>

using namespace std;

int main(){
    long long result = 0;
    string a;
    cin>>a;
    char ch[32] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'};
    map<char,int> ma;
    for(int i = 0; i< 32;i++){
        int temp = i;
        int res = 0;
        while(temp){
            if(temp & 1){
                res++;
            }
            temp>>=1;
        }
        ma[ch[i]] = res;
    }
    for(long long i = 0; i< a.length();i++){
        result += ma[a[i]];
    }
    cout<<result;
    return 0;
}