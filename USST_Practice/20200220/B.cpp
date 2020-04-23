#include<iostream>
#include<algorithm>
#include<map>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> ma;
    for(int  i= 1 ;i<10005; i++){
        int temp = i;
        int res = temp;
        while(temp){
            res += (temp % 10);
            temp /= 10;
        }
        ma[res]++;
    }
    for(int i= 1 ;i<=10000; i++){
        if(ma[i] == 0){
            cout<<i<<endl;
        }
    }
    return 0;
}