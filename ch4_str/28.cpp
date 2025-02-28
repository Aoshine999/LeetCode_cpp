#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    void getNext(int *next, const string &s){
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j+1]){
                j = next[j];
            }
            if(s[i] == s[j+1]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;

        vector<int> next(needle.size());
        getNext(&next[0],needle);
        int j = -1;
        for(int i = 0; i < haystack.size(); i++){
            while(j >= 0 && needle[j+1] != haystack[i]){
                j = next[j];
            }
            if(needle[j+1] == haystack[i]) j++;

            if(j == (needle.size() - 1)){
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
