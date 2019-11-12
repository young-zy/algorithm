#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long long a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    long long count = 0;
    int temp = 0;
    for(int i = 0; i<n ; i++){
        map<int,int> ma;
        cin>>temp;
        long long ccount = 0;
        while(temp){
            int n = temp % 10;
            if(n == 4 || n == 7){
               ccount++;
            }
            temp /=10;
        }
        if(ccount <= k){
            count++;
        }else{
            
        }
    }
    cout<<count;
    return 0;
}