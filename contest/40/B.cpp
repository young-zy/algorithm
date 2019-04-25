#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

int a[100005];
//int form[200005];
//int a[100];
//int form[100];

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin>>n;
    int maxnum = 0;
    map<int,int> form;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
        maxnum = max(maxnum,a[i]);
    }
    //memset(form,-1,sizeof(form));
    for(int i = 0; i< n ;i++){
        int temp = a[i];
        int count = 0;
        while(temp >= 1){
            form[temp>>=1] += ++count;
        }
        temp = a[i];
        count = 0;
        while(temp <= maxnum*2){
            form[temp<<=1] += ++count;
        }
    }
    int minnum = 300000;
    // for(int i = 0; i<= maxnum*2; i++){
    //     minnum = min(minnum,form[i]);
    // }
    for(auto it = form.begin(); it != form.end();it++){
        minnum = min(minnum,it->second);
    }
    cout<<minnum;
    return 0;
}