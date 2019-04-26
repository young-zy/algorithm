#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    map<int ,int> ma;
    int maxnum = 0;
    for(int i = 0; i< n; i++){
        int temp;
        cin>>temp;
        ma[temp]++;
        maxnum = max(maxnum,ma[temp]);
    }
    cout<<maxnum;
    return 0;
}