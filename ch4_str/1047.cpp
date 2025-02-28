#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        for(char ch: s){
            if(!s1.empty() && s1.top() == ch){
                s1.pop();
            }
            else s1.push(ch);
        }
        string res;
        while(!s1.empty()){
            res += s1.top();
            s1.pop();
        }
        reverse(res.begin(),res.end());
        return res;        
    }
};