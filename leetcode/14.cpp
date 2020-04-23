#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlength = 0x3f3f3f3f;
        for(auto it:strs){
            minlength = min(minlength,(int)it.length());
        }
        int count = 0;
        int flag = 1;
        for(count = 0; count<minlength; count++){
            auto it = strs.begin();
            char ch = (*it)[count];            
            for(;it != strs.end();it++){
                if((*it)[count] != ch){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        return strs[0].substr(0,count);
    }
};

int main(){
    long long a = INFINITY;
    cout<<a;
}