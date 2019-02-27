#include<bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    string b="";
    int flag = 0;
    if(a.length() % 2 == 0){
        flag = 1;
    }
    while(a.length()!=0){
        if(flag == 1){
            b.insert(0,1,a[a.length()-1]);
            a.erase(a.length()-1,1);
            flag = 0;
        }else{
            b.insert(0,1,a[0]);
            a.erase(0,1);
            flag = 1;
        }
        
    }
    cout<<b;
    //system("pause");
    return 0;
}