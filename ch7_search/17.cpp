#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

class Solution {
    public:
        vector<string> res;
        vector<int> nums;
        string s;
        vector<string> letterCombinations(string digits) {
            for(int i = 0; i < digits.size(); i++){
                nums.push_back(digits[i]-'0');
            }
            int size = nums.size();
            leComb(size,0);
            string st = res.back();
            if(st.empty()){
                res.clear();
            }
            return res;
        }

        void leComb(int size,int stIdx){
            if(size == 0){
                res.push_back(s);
                return ;
            }
            for(int i = stIdx; i < nums.size(); i++){
                for(char c : letterMap[nums[i]]){
                    s.push_back(c);
                    leComb(size-1,i + 1);
                    s.pop_back();
                }
            }
        }
};