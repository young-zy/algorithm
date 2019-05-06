#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

map<long,int> ma;

// long f(long a){
//     int count = 0;
//     a++;
//     while(a % 10 == 0){
//         a /= 10;
//     }
//     if(ma[a] == 0){
//         ma[a]++;
//         count += f(a);
//         count++;
//         return count;
//     }else{
//         return count;
//     }
// }

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long n;
    cin>>n;
    //long res = f(n);
    while(ma[n] == 0){
        ma[n]++;
        n++;
        while(n % 10 == 0){
            n /= 10;
        }
    }
    ma[n]++;
    cout<<ma.size();
    return 0;
}