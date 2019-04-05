#include<bits/stdc++.h>

using namespace std;

long long a[200005];

int main(){
    long long n,k;
    cin>>n;
    set<long long> se;
    long long temp = 0;
    for(long long i = 0; i< n-1 ; i++){
        scanf("%lld",&a[i]);
        if(a[i] == 0){
            cout<<"-1";
            return 0;
        }
        se.insert(temp);
        temp += a[i];
    }
    se.insert(temp);
    if(se.size() != n){
        cout<<-1;
        return 0;
    }else{
        long long min = *se.begin();
        long long max = *(--se.end());
        if(max - min != n - 1){
            cout<<-1;
            return 0;
        }else{
            //if(*se.begin() < 0){
                long long start = -(*se.begin())+1;
                cout<<start<<" ";
                for(long long i = 0; i < n-1 ; i++){
                    start += a[i];
                    cout<<start<<" ";
                }
            // }else{
            //     long long start = a[0] - *se.begin();
            //     cout<<start<<" ";
            //     for(long long i = 0; i < n-1 ; i++){
            //         start += a[i];
            //         cout<<start<<" ";
            //     }
            // }
            
        }
    }
    return 0;
}