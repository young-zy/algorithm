#include<bits/stdc++.h>

using namespace std;

int a[10005];

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t ; i++){
        int n,m,k;
        cin>>n>>m>>k;
        map<int,int> ma;
        //map<int,int> ma2;
        long long count = 0;
        for(int j = 0; j< n ; j++){
            scanf("%d",&a[j]);
            ma[a[j]]++;
        }
        for(int j = 1; j<= m;j++){
            ma[j] /= k;
        }
        for(int j = 0; j < n/2 ; j++){
            if(ma[a[j]] > 0){
                ma[a[j]]--;
                count++;
                //ma2[a[i]]++;
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}