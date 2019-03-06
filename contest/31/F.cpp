#include<bits/stdc++.h>

using namespace std;

int main(){
    char ch;
    int n;
    cin>>ch>>n;
    char b[n][n];
    string a[n];
    for(int i = 0;i<n;i++){
        getchar();
        for(int j =0 ;j<n;j++){
            a[i].append(1,getchar());
        }
    }
    int flag = 1;
    for(int i =0 ;i<n ;i++){
        if(a[i] == a[n-1-i]){
            continue;
        }else{
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout<<"bu yong dao le"<<endl;
    }
    for(int i = n-1; i>=0;i--){
        for(int j = n-1; j>=0;j--){
            if(a[i][j] != ' '){
                cout<<ch;
            }else{
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}