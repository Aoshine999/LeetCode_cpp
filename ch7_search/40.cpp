#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N = 1010;


class Solution {
    public:
        vector<vector<int>> res;
        vector<int> cb;
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<bool> used(candidates.size(),false);
            
            sort(candidates.begin(),candidates.end());
            comSum(candidates,target,0,used);
            return res;
        }

        void comSum(vector<int> & candidates, int target, int stIdx, vector<bool> used){
            if(target == 0){
                res.push_back(cb);
                return ;
            }
            
            for(int i = stIdx; i < candidates.size(); i++){
                if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;


                if(target - candidates[i] >= 0){
                    used[i] = true;
                    cb.push_back(candidates[i]);
                    comSum(candidates,target - candidates[i],i + 1,used);
                    cb.pop_back();
                    used[i] = false;
                }
            }
        }
    };