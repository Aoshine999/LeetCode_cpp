#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < (int)nums.size() - 3; i++){
            if(nums[i] > target && nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            vector<int> subvec = vector<int>(nums.begin() + i + 1,nums.end());
            vector<vector<int>> three_sum = threeSum(subvec,target-nums[i]);
            for(vector<int> a: three_sum){
                a.push_back(nums[i]);
                res.push_back(a);
            }
        }

        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums,int target){
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < target) l++;
                else if(nums[i] + nums[l] + nums[r] > target) r--;
                else{
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    l++;
                    r--;
                }
              
            }
        }
        return res;
    }
};