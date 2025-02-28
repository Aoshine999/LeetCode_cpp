#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
    public:
        string str;
        vector<string> res;
        bool flag;
        vector<string> restoreIpAddresses(string s) {
            if(s.size() < 4 || s.size() > 12) return res;
            reIpAd(s,0,0);
            return res;
        }
        void reIpAd(string s,int stIdx,int level){
            if(level == 3){
                int num = strToInt(s,stIdx,s.size()-1);
                if(flag == 1){
                    if(num >= 0 && num <= 255){
                        string str1 = str;
                        str1 += s.substr(stIdx,s.size() - stIdx);
                        res.push_back(str1);
                    }
                }
                return ;
            }

            for(int i = stIdx; i < s.size(); i++){
                int num = strToInt(s,stIdx,i);
                if(flag == 1){
                    if(num >=0 && num <= 255){
                        str += s.substr(stIdx,i - stIdx + 1);
                        str.push_back('.');
                        reIpAd(s,i+1,level+1);
                        str.pop_back();
                        int size = s.substr(stIdx,i - stIdx + 1).length();
                        while(size--){
                            str.pop_back();
                        }
                    }
                }
            }

        }
        int strToInt(string s, int st, int end){
            flag = 1;
            if(s[st] == '0' && st != end){
                flag = 0;
            }
            if(st > end){
                flag = 0;
                return 0;
            }
            int sum = 0;
            for(int i = st; i <= end; i++){
                sum = sum * 10 + s[i] - '0'; 
                if(sum > 255){
                    flag = 0;
                    return 0;
                }
            }
            return sum;
        }
};