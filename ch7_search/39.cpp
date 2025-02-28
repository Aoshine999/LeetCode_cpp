#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;



class Solution {
    public:
        vector<vector<int>> res;
        vector<int> cb;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            comSum(candidates,target,0);
            return res;
        }

        void comSum(vector<int> & candidates, int target, int stIdx){
            if(target == 0){
                res.push_back(cb);
                return ;
            }
            
            for(int i = stIdx; i < candidates.size(); i++){
                if(target - candidates[i] >= 0){
                    cb.push_back(candidates[i]);
                    comSum(candidates,target - candidates[i],i);
                    cb.pop_back();
                }
            }
        }
    };