#include <bits/stdc++.h>

using namespace std;

int main()
{
    long h;
    int n;
    cin>>n>>h;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int flag2 = 1;
    for(int i = 1; i<= n ; i++){
        sort(a,a+i);
        long temph = h;
        int flag = 1;
        for(int j = i-1; j >=0;j-=2){
            if(a[j] <= temph){
                if(j == 0){
                    temph -= a[j];
                }else if(a[j-1] <= temph){
                    temph -= max(a[j],a[j-1]);
                }else{
                    flag = 0;
                    break;
                }
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout<<i-1;
            flag2 =0;
            break;
        }
    }
    if(flag2 == 1){
        cout<<n;
    }
    return 0;
}