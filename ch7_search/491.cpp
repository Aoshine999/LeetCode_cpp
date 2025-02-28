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
        
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            
            findSubSeq(nums,0);
            return res;
        }

        void findSubSeq(vector<int>& nums, int stIdx){
            if(path.size() >= 2){
                res.push_back(path);
            }
            if(stIdx >= nums.size()) return ;
            bool used[301] = {0};
            for(int i = stIdx; i < nums.size(); i++){
                if(path.empty()){
                    if(used[nums[i] + 100] == true){
                        continue;
                    }
                    used[nums[i] + 100] = 1;
                    path.push_back(nums[i]);
                    findSubSeq(nums,i+1);
                    path.pop_back();

                }else{
                    int num = path.back();
                    if(nums[i] >= num){
                        if(used[nums[i] + 100] == true){
                            continue;
                        }else{
                            used[nums[i] + 100] = 1;
                            path.push_back(nums[i]);
                            findSubSeq(nums,i+1);
                            path.pop_back();
                        }
                    }
                }
            }
        }
};

int main(){
    vector<int> nums = {4,4,3,2,1};

    return 0;
}