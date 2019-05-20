#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

char a[5][5] = {
    {'a','e','i','o','u'},
    {'e','i','o','u','a'},
    {'i','o','u','a','e'},
    {'o','u','a','e','i'},
    {'u','a','e','i','o'}
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    char b[] ={'a','e','i','o','u'}; 
    
    if(k < 25){
        cout<<-1;
        return 0;
    }
    int flag = 0;
    int n,m;
    for(int i = 5; i<=sqrt(k);i++){
        if(k % i == 0){
            n = i;
            m = k /i;
            if(m <5){
                continue;
            }
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<-1;
        return 0;
    }
    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<a[i % 5][j % 5];
        }
    }
    
    return 0;
}