#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> num(numCourses);
        vector<int> res;
        deque<int> edge[numCourses];
        for(auto it:prerequisites){
            num[it[0]]++;
            edge[it[1]].push_back(it[0]);
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
            res.push_back(temp);
            qu.pop();
            for(auto it:edge[temp]){
                if(--num[it] == 0){
                    qu.push(it);
                    count++;
                }
            }
        }
        if(count != numCourses){
            res.clear();
        }
        return res;
    }
};

int main(){

}