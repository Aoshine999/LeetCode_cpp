#include<iostream>
using namespace std;
const int N = 10010;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for(int i = 0; i < s.size(); i++){
            a[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < t.size(); i++){
            a[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++){
            if(a[i] != 0) return false;
        }
        return true;
    }
};

int main(){
    string s = "aabbbb";
    string t = "aaaabb";
    Solution so;
    bool f = so.isAnagram(s,t);
    cout << f;
    return 0;
}