#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[1000005] = {0};
int b[1000005] = {0};

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    for(int i = 0; i<n ; i++){
        int temp;
        cin>>temp;
        if(temp & 1){
            a[temp/2] = 1;
        }else{
            b[temp/2] = 1;
        }
    }
    int max = 0;
    int maxind = 0;
    int count = 0;
    int countind = 1;
    a[m/2] = 1;
    b[m/2+1] = 1;
    for(int i = 0; i<=m/2;i++){
        if(a[i] == 0){
            count++;
        }else{
            if(count > max){
                maxind = countind;
                max = count;
            }
            countind = i * 2 + 3;
            count = 0;
        }
    }
    countind = 2;
    for(int i = 1; i<=m/2+1;i++){
        if(b[i] == 0){
            count++;
        }else{
            if(count > max || count == max && countind < maxind){
                maxind = countind;
                max = count;
            }
            countind = i * 2 + 2;
            count = 0;
        }
    }
    cout<<maxind<<" "<<max;
    return 0;
}