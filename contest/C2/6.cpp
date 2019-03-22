#include<bits/stdc++.h>

using namespace std;

long a[10005];

int main(){
    int t;
    cin>>t;
    for(int i =0 ;i<t;i++){
        int n;
        stack<long> s;
        cin>>n;
        for(int j =0 ;j<n;j++){
            cin>>a[j];
        }
        long min = a[0];
        long res = 0;
        long newmin = 0;
        long start = 0;
        for(int j = 0; j< n;j++){
            if(s.empty()){
                s.push(a[j]);
            }else{
                if(a[j] > s.top()){
                    s.push(a[j]);
                }else if(a[j]<min){
                    long temp = j-start-1;
                    while(!s.empty()){
                        s.pop();
                    }
                    if(temp > res){
                        res = temp;
                    }
                    min = a[j];
                    start = j;
                    s.push(a[j]);
                }else{
                    newmin = a[j];
                    continue;
                }
            }
        }
        long temp = n-1-start;
        if(temp > res){
            res = temp;
        }
        cout<<res<<endl;
    }
    return 0;
}