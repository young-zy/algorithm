#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin>>n;
    string a;
    cin>>a;
    int time = 0;
    map<char,int> ma;
    for(long i = 0; i< a.length();i++){ 
        ma[a[i]]++;
    }
    int index = 0;
    int index2 = 0;
    while(a.length()>11){
        if(time % 2 == 0){
            for(long i = index2; i<a.length();i++){
                if(a[i] != '8'){
                    a.erase(i,1);
                    break;
                    index2 = i-2;
                    if(index2 < 0){
                        index2 = 0;
                    }
                }
                if(i == a.length()-1){
                    index2 = i-2;
                    a.erase(i,1);
                }
            }
        }else{
            for(long i = index; i<n ; i++){
                if(a[i] == '8'){
                    a.erase(i,1);
                    index = i-2;
                    if(index < 0){
                        index = 0;
                    }
                    break;
                }
                if(i == a.length()-1){
                    index = i-2;
                    a.erase(i,1);
                }
            }
        }
        time++;
    }
    
    if(a[0] == '8'){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}