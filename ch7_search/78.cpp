#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<int> path;
        vector<vector<int>> subsets(vector<int>& nums) {
            path.clear();
            res.clear();
            subset2(nums,0);
            return res;
        }

        void subset2(vector<int>& nums, int stIdx){
            res.push_back(path);
            if(stIdx >= nums.size()){
                return ;
            }

            for(int i = stIdx; i < nums.size(); i++){
                path.push_back(nums[i]);
                subset2(nums,i + 1);
                path.pop_back();
            }
        }
};