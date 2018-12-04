#include <bits/stdc++.h>

using namespace std;

int main(){
    char a[10000];
    cin.getline(a,10000);
    for(int i = 0; i< 10000-3;i++){
        if(a[i] == 's'){
            if(a[i+1] == 'h' && a[i+2] == 'u' && a[i+3] == 'i'){
                cout<<"yes";
                return 0;
            }
        }
    }
    cout<<"no";
    return 0;
}