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
    bool isValid(string s) {
        stack<char> mat;
        for(char s1: s){
            if(s1 == '(' || s1 == '{' || s1 == '['){
                mat.push(s1);
            }else if(s1 == ')' && !mat.empty() && mat.top() == '('){
                mat.pop();
            }else if(s1 == '}' && !mat.empty() && mat.top() == '{'){
                mat.pop();
            }else if(s1 == ']' && !mat.empty() && mat.top() == '['){
                mat.pop();
            }else{
                return false;
            }
        }
        return mat.empty();   
    }
};