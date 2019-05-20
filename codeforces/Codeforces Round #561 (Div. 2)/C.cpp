#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

long a[100005];

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 0; i<n ; i++){
        cin>>a[i];
    }
    long long count = 0;
    sort(a,a+n);
    for(int i = 0; i<n ; i++){
        for(int j = i; j < n;j++){
            if(i == j){
                break;
            }
            if(a[i] < 0){
                if(a[j] > -a[i] || a[j] < a[i]/2){
                    break;
                }else{
                    count++;
                }
            }else{
                if(a[j] < a[i]*2){
                    break;
                }else{
                    count++;
                }
            }
        }
    }

    return 0;
}