#include<bits/stdc++.h>

using namespace std;

int a[100005];
int sum[100005];

int main(){
    int t;
    cin>>t;
    for(int i = 0; i< t ; i++){
        int n,s;
        scanf("%d %d",&n,&s);
        sum[0] = 0;
        for(int i = 0; i<n;i++){
            scanf("%d",&a[i]);
        }
        int maxcount = 0;
        for(int i = 0; i < n; i++)
        {
            map<int,int> ma;
            int count = 0;
            for(int j = i; j < n; j++)
            {
                
                ma[a[j]]++;
                if(ma[a[j]] <= s){
                    count++;
                }else{
                    if(ma[a[j]] == s+1){
                        count -= ma[a[j]];
                        count++;
                    }
                }
                maxcount = max(maxcount,count);
            }
            
        }
        printf("Case #%d: %d\n",i+1,maxcount);
    }
    return 0;
}