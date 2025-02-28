#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0,r = s.size() - 1;
        while(l < r){
            swap(s[l],s[r]);
            l++;
            r--;
        }      
    }
};