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
    vector< vector<int> > threeSum( vector<int> & nums) {
        vector< vector<int> > result;
        if( nums.size() <= 2 ){
            return result;
        }
        sort( nums.begin(), nums.end() );
        for( int i = 0; i < nums.size()-2;){
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];
            while( left < right ){
                int sum = nums[ left ] + nums[ right ];
                if(sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else{
                    vector<int> temp = { nums[i], nums[left], nums[right] };
                    result.push_back(temp) ;
                    while( left < nums.size() && nums[ left ] == temp[1] ){
                        left++;
                    }
                    while( right >= i && nums[ right ] == temp[2] ){
                        right--;
                    }
                }
            }
            int num = nums[i];
            while(i < nums.size() -2 && nums[i] == num){
                i++;
            }
        }
        return result;
    }
};