#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> num(numCourses);
        deque<int> edge[numCourses];
        for(auto it:prerequisites){
            num[it[1]]++;
            edge[it[0]].push_back(it[1]);
        }
        queue<int> qu;
        int count = 0;
        for(int i = 0; i<numCourses ;i++){
            if(num[i] == 0){
                qu.push(i);
                count++;
            }
        }
        while(!qu.empty()){
            int temp = qu.front();
            qu.pop();
            for(auto it:edge[temp]){
                if(--num[it] == 0){
                    qu.push(it);
                    count++;
                }
            }
        }
        if(count == numCourses){
            return true;
        }else{
            return false;
        }
        
    }
};

int main(){
    vector<vector<int>> prerequisites = {{1,0}};
    cout<<Solution().canFinish(2,prerequisites);
}