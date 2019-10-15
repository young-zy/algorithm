#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

deque<long long> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k,s;
    cin>>n>>k>>s;
    if((n-1)*k <s || k>s){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        long long a = 0,b=0,c=0;
        long long flag = 0;
        for(long long i = s/(n-1); i>=0; i--){
            for(long long j= i*(n-1);j >=0;j--){
                int temp = j%2;
                if(i+j == k && j == 0 ||i + s-i*(n-1)-j + 1 == k && s-j-i*(n-1) < n && j != 0){
                    flag = 1;
                    a = i;
                    b = ;
                    c = j;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        long long last = 1;
        for(long long i = 0; i<a ;i++){
            if(last == 1){
                last = n;
                cout<<n<<" ";
            }else{
                last = 1;
                cout<<1<<" ";
            }
        }
        for(long long i = 0; i<b ; i++){
            if(last == 1){
                last = 2;
                cout<<2<<" ";
            }else if(last == 2){
                last = 1;
                cout<<1<<" ";
            }else if(last == n){
                cout<<n-1<<" ";
                last = n-1;
            }else{
                cout<<n<<" ";
                last = n;
            }
        }
        if(c == 0){
            
        }
        if(last + c <= n){
            cout<<last+c;
        }else{
            cout<<last-c;
        }
    }
    return 0;
}