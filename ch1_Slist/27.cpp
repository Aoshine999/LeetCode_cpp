#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            if(nums[l] == val){
                while(r >= 0 && nums[r] == val){
                    nums.pop_back();
                    r--;
                }

                if(l < r){
                    swap(nums[l],nums[r]);
                    l++;
                }
            }
            else l++;
        }
        return nums.size();
    }
};
int main(){
    vector<int> nums = {1};
    int val = 1;
    Solution s;
    s.removeElement(nums,val);
    return 0;
}