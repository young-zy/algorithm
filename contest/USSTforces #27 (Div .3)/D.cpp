#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    cin>>n;
    long long sum = 0;
    for(int i = 0; i<n.length();i++){
        sum += n[i] - '0';
    }
    long long count = 0;
    if(n.size() == 1){
        count = 0;
    }else{
        count = 1;
    }
    while(1){
        if(sum <10){
            break;
        }
        long long temp = 0;
        while(sum){
            temp += sum%10;
            sum /=10;
        }
        count++;
        sum = temp;
    }
    cout<<count;
    return 0;
}