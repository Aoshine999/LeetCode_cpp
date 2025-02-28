#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
const int N = 3010;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int l,r;
        for(int i = 0; i< nums.size(); i++){
            if(nums[0] > 0) return res;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            l = i + 1;
            r = nums.size() - 1; 
            while(l < r){
                if(nums[i] + nums[l] + nums[r] > 0) r--;
                else if(nums[i] + nums[l] + nums[r] < 0) l++;
                else{
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;

                    l++;
                    r--;
                }
            }    
        }
        return res;    
    }
};