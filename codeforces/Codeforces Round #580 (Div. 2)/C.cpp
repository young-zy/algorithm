#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n % 2 == 0){
        cout<<"NO";
        return 0;
    }
    a[0] = 1;
    int n2 = 2*n;
    int index = n;
    int flag = 1;
    for(int i = 2; i <= 2*n ; i++){
        a[index] = i;
        if(flag == 0){
            flag = 1;
            index += n;
        }else{
            flag = 0;
            index++;
        }
        index %= n2;
    }
    cout<<"YES"<<endl;
    for(int i = 0; i< n2;i++){
        cout<<a[i];
        if(i != n2-1){
            cout<<" ";
        }
    }
    return 0;
}