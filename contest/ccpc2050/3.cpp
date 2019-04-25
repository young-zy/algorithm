#include<bits/stdc++.h>

using namespace std;

int main(){
    long t;
    cin>>t;
    for(int i = 0; i< t ; i++){
        long n,m,k;
        long a,b,c;
        cin>>n>>m>>k>>a>>b>>c;
        long long price[k+1];
        for(int j = 0; j<=k ; j++){
            long long priceb = 0;
            if((double)b/3 < (double)a/2){
                priceb += (n+j)/3 * b;
                if((n+j) % 3 != 0){
                    priceb += min(a,b);
                }
                priceb += (m+j)/3 * b;
                if((m+j) % 3 != 0){
                    priceb += min(a,b);
                }
            }else{
                priceb += (n+j)/2 * a;
                if((n+j) % 2 != 0){
                    priceb += min(min(a,b),b-a);
                }
                priceb += (m+j)/2 * a;
                if((m+j) % 2 != 0){
                    priceb += min(min(a,b),b-a);
                }
            }
            priceb += (k-j)*c;
            price[j] = priceb;
        }
        long long min = 999999999999999;
        for(int j = 0; j< k+1;j++){
            if(price[j] < min){
                min = price[j];
            }
        }
        cout<<min<<endl;
    }
    return 0;
}