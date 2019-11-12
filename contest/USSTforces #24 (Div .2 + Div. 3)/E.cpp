#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a;
signed main(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<2*n-1;++i){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int t=0;
    int flag=0; 
    for(int i=0;i<a.size();++i){
        if(a[i]<0){
            t++;
        }
        if(a[i]==0){
            flag=1;
        } 
    }
    int ans=0;  
    if(t==2*n-1){
        if(!(n %2)){
            for(int i=0;i<(int)a.size()-1;++i){
                ans+=abs(a[i]);
            } 
            cout<<ans+a[a.size()-1];
        }else{
            for(int i=0;i<(int)a.size();++i){
                ans+=abs(a[i]);
            } 
            cout<<ans;
        }
        return 0; 
    }
    if(n%2==0&&t%2==1&&flag==0){
        int Sum=0;
        for(int i=0;i<(int)a.size();++i){
            Sum+=abs(a[i]);
        } 
        for(int i=0;i<(int)a.size();++i){
            a[i]=abs(a[i]);
        } 
        sort(a.begin(),a.end());
        Sum=Sum-2*a[0];
        cout<<Sum;
    }else{
        for(int i=0;i<a.size();++i){
            ans+=abs(a[i]);
        } 
        cout<<ans;
    }
    return 0;
}
/*
5
-1 -1 -1 -1 -1 -1 -1 -1 -1
*/