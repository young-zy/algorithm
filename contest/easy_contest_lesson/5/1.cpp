#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i =0 ; i< t ; i++){
        string a;
        cin>>a;
        int k;
        cin>>k;
        int count = 0;
        for(int i =0 ;i< a.length()-1;i++){
            if(a[i] > a[i+1]){
                a.erase(i,1);
                count++;
                i=-1;
            }
            if(count >= k){
                break;
            }
        }
        while(count < k){
            a.erase(a.length()-1);
            count++;
        }
        cout<<a<<endl;
    }
    return 0;
}