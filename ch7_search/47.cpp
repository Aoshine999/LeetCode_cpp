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
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<bool> flagIdx(10,0);
            permuteUqe1(nums,flagIdx);
            return res;
        }
        void permuteUqe1(vector<int>& nums, vector<bool>& flagIdx){
            if(path.size() == nums.size()){
                res.push_back(path);
                return;
            }
            bool flags[30] = {0};
            for(int i = 0; i < nums.size(); i++){
                if(flags[nums[i] + 10] == 0 && flagIdx[i] == 0){
                    flags[nums[i] + 10] = 1;
                    flagIdx[i] = 1;
                    path.push_back(nums[i]);
                    permuteUqe1(nums,flagIdx);
                    path.pop_back();
                    flagIdx[i] = 0;
                }else{
                    continue;
                }
            }
        }
};