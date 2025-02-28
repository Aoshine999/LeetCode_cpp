#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums_12;
        int res = 0;
        for(int i : nums1){
            for(int j : nums2){
                nums_12[i + j] += 1;
            }
        }
        for(int i : nums3){
            for(int j : nums4){
                if(nums_12.find(0 - i - j) != nums_12.end()){
                    res += nums_12[0 - i - j];
                }
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1 = {0};
    vector<int> nums2 = {0};
    vector<int> nums3 = {0};
    vector<int> nums4 = {0};
    cout << s.fourSumCount(nums1,nums2,nums3,nums4);
}