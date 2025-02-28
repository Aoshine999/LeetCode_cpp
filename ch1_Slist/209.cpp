#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int res = INT32_MAX;
       int sum = 0;
       int i = 0;
       int subLength = 0;
       for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subLength = (j - i + 1);
                res = res < subLength ? res : subLength;
                sum -= nums[i++];
            }
       }
       
       return res == INT32_MAX ? 0 : res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    s.minSubArrayLen(target,nums);
    return 0;
}