#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0 ; i<t;i++){
        string a;
        cin>>a;
        string b = "2050";
        int j = 0;
        int flag  = 1;
        while(j != a.length()){
            int k = 0;
            for(; k <= 3;k++){
                if(a[j] !=  b[k]){
                    flag = 0;
                    break;
                }
                j++;
            }
            if(flag == 0){
                break;
            }
        }
        if(flag == 0){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}