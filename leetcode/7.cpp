#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

class Solution {
public:
    long long reverse(long long x) {
        long long num = 0;
        bool flag = false;
        if(x < 0){
            flag = true;
            x = -x;
        }
        vector<long long> ve;
        while(x){
            long long temp = x%10;
            if(temp == 0 && num == 0){

            }else{
                ve.push_back(temp);
                num++;
            }
            x/=10;
        }
        long long ans = 0;
        for(auto it:ve){
            for(long long i = 0; i<num-1 ;i++){
                it*=10;
            }
            ans += it;
            num--;
        }
        if(flag){
            ans = -ans;
        }
        if(ans > 2147483647 || ans < -2147483648){
            return 0;
        }else{
            return (int)ans;
        }
        
    }
};