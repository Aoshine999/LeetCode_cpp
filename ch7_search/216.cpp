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
        vector<int> comb;
        vector<vector<int>> combinationSum3(int k, int n) {
            combSum(k,n,1);
            return res;
        }
        void combSum(int k, int n, int stIdx){
            if(k == 0 && n == 0){
                res.push_back(comb);
                return ;
            }else if(k == 0){
                return ;
            }
            int k = min(9,n);
            for(int i = stIdx; i <= k; i++){
                comb.push_back(i);
                combSum(k-1,n-i,i+1);
                comb.pop_back();
            }
        }
};