#include<iostream>
#include<vector>
#include<stack>
const int N = 10010;
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        stack<int> opt;
        while(nums.size() > 0 && nums.back() > 0){
                opt.push(nums.back());
                nums.pop_back();
        }
        while(nums.size() > 0 && opt.size() > 0){
            if(opt.top() > abs(nums.back())){
                res.push_back(nums.back() * nums.back());
                nums.pop_back();
            }
            else{
                res.push_back(opt.top() * opt.top());
                opt.pop();
            } 
        }
        while(opt.size() > 0){
            res.push_back(opt.top() * opt.top());
            opt.pop();
        }
        while(nums.size() > 0){
            res.push_back(nums.back() * nums.back());
            nums.pop_back();
        }

        return res;
    }
};
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> res(nums.size());
        while(l <= r){
            if(nums[l] * nums[l] > nums[r] * nums[r]){
                res[index--] = nums[l] * nums[l];
                l++;
            }
            else{
                res[index--] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    int val = 1;
    Solution s;
    vector<int> res = s.sortedSquares(nums);
    return 0;
}