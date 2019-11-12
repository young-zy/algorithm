#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y;
    cin>>y;
    y++;
    while(1){
        int temp = y;
        set<int> se;
        while(temp){
            se.insert(temp % 10);
            temp /= 10;
        }
        if(se.size() >= 4){
            break;
        }
        y++;
    }
    cout<<y;
    return 0;
}