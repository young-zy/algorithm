#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    for(int te = 0; te < t ; te++){
        int n;
        long m;
        cin>>n>>m;
        int a[2*n+5];
        memset(a,0,sizeof(a));
        int flag = 1;
        for(long i = 0; i< m;i++){
            int _1,_2;
            cin>>_1>>_2;
            if(flag == 0){
                continue;
            }
            if(a[_1] == 0){
                if(a[_1+n] == 0){
                    if(a[_2] == 0 && a[_2+n] == 0){
                        a[_1] = 1;
                        a[_2+n] = 1;
                    }else if(a[_2] == 1){
                        a[_1+n] = 1;
                    }else{
                        a[_1] = 1;
                    }
                }else{
                    if(a[_2] == 0 && a[_2] == 0 || a[_2] == 1){
                        a[_2] = 1;
                    }else{
                        cout<<"Warning"<<endl;
                        flag = 0;
                        continue;
                    }
                }
            }else{
                if(a[_2] == 1){
                    cout<<"Warning"<<endl;
                    flag = 0;
                    continue;
                }
                if(a[_2+n] == 1){
                    
                }else if(a[_2+n] == 0 && a[_2] == 0){
                    a[_2+n] = 1;
                }
            }
        }
        if(flag == 0){
            continue;
        }else{
            cout<<"Ok"<<endl;
        }
    }
    return 0;
}