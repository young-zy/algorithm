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
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;  //result of the requirement
        
        map<int, int> mapOfElement; //count of each element
        for(auto it:nums){
            mapOfElement[it]++;
        }
        
        for(int i = 0; i < nums.size(); i++ ){
            mapOfElement[ nums[i] ]--;
            if(mapOfElement[ target - nums[i] ]){
                result.push_back(i);
                for(int j = 0; j < nums.size() ; j++){
                    if( i == j ){
                        continue;
                    }
                    if(nums[j] == target - nums[i]){
                        result.push_back(j);
                        break;
                    }
                }
                break;
            }
            mapOfElement[ nums[i] ]++;
        }
        return result;
    }
};