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
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for(string s: tokens){
            if(s == "+"){
                int x1 = res.top();
                res.pop();
                int x2 = res.top();
                res.pop();
                int num = x1 + x2;
                res.push(num);
            }else if(s == "-"){
                int x1 = res.top();
                res.pop();
                int x2 = res.top();
                res.pop();
                int num = x2 - x1;
                res.push(num);
            }else if(s == "*"){
                int x1 = res.top();
                res.pop();
                int x2 = res.top();
                res.pop();
                int num = x1 * x2;
                res.push(num);
            }else if(s == "/"){
                int x1 = res.top();
                res.pop();
                int x2 = res.top();
                res.pop();
                int num = x2 / x1;
                res.push(num);
            }else{
                int num = strNumTrans(s);
                res.push(num); 
            }
        }
        return res.top();
    }
    int strNumTrans(string s){
        int sum = 0;
        if(s[0] == '-' && s.size() > 1){
            for(int i = 1; i < s.size(); i++){
                sum = sum * 10 + s[i] - '0';
            }
            sum *= -1;
        }else{
            for(int i = 0; i < s.size(); i++){
                sum = sum * 10 + s[i] - '0';
            }
        }
        return sum;
    }
};
int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    Solution s;
    int res = s.evalRPN(tokens);

    return 0;
}