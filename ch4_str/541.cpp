#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int l = 0;
        while(l + 2 * k <= s.size()){
            int r = l + k - 1;
            int l1 = l;
            while(l1 < r){
                swap(s[l1],s[r]);
                l1++;
                r--;
            }
            l = l + 2 * k;
        }
        if(l + k - 1 <= s.size() - 1){
            int r = l + k - 1;
            int l1 = l;
            while (l1 < r)
            {
                swap(s[l1],s[r]);
                l1++;
                r--;
            }
            
        }else{
            int r = s.size() - 1;
            int l1 = l;
            while (l1 < r)
            {
                swap(s[l1],s[r]);
                l1++;
                r--;
            }
        }

        return s;
    }
};
