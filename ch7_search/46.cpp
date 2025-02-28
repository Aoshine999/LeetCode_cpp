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
        vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> flag(30,0);
            permute1(nums,flag);
            return res;
        }
        void permute1(vector<int> &nums, vector<bool> &flag){
            if(path.size() == nums.size()){
                res.push_back(path);
                return ;
            }
            for(int i = 0; i < nums.size(); i++){
                if(!flag[i]){
                    flag[i] = true;
                    path.push_back(nums[i]);
                    permute1(nums,flag);
                    flag[i] = false;
                    path.pop_back();
                }
            }
        }
};