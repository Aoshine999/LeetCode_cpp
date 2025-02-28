#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    void reverse(string &s,int start,int end){
        for(int i = start, j = end; i < j; i++,j--){
            swap(s[i],s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s,0,s.size()-1);
        int l = 0 , r = 0;
        while(r < s.size()){
            if(s[r] != ' '){
                r++;
            }else{
                reverse(s,l,r-1);
                r++;
                l = r;
            }
        }
        reverse(s,l,r-1);
        return s;
    }

    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){  //找到第一个字符
                if(slow!=0) s[slow++] = ' ';
                while(i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow 
    }
};