#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i =0 ;i < t ; i++){
        int m,n;
        cin>>n>>m;
        int a[n][m];
        for(int j = 0; j <n ; j++){
            for(int k = 0; k < m ;k++){
                cin>>a[j][k];
            }
        }
        int count = 0;
        for(int j = 0; j<n ; j++){
            if(j  % 2 == 0){
                for(int k = 0; k<m ;k++){
                    cout<<a[j][k];
                    count++;
                    if(count != n * m){
                        cout<<" ";
                    }
                }
            }else{
                for(int k = m-1; k>=0 ;k--){
                    cout<<a[j][k];
                    count++;
                    if(count != n * m){
                        cout<<" ";
                    }
                }
            }
            
        }
        cout<<endl;
    }
    return 0;
}