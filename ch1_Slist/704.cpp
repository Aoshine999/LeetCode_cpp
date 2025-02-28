#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;
        while (l <= r)
        {
            mid = l + r >> 1;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else return mid;
        }
        if(target != nums[mid]) return -1;
    }
};