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
        vector<vector<string>> res;
        vector<string> path;
        vector<vector<string>> partition(string s) {
            partit(s,0);
            return res;
        }
        void partit(string s,int stIdx){
            if(stIdx >= s.size()){
                res.push_back(path);
                return ;    
            }

            for(int i = stIdx; i < s.size(); i++){
                if(isPalindrome(s,stIdx,i)){
                    string str = s.substr(stIdx,i - stIdx + 1);
                    path.push_back(str);
                    partit(s,i+1);
                    path.pop_back();
                }
            }
        }
        bool isPalindrome(string s, int start, int end){
            for(int i = start, j = end; i < j; i++, j--){
                if(s[i] != s[j]) return false;
            }

            return true;
        }
};