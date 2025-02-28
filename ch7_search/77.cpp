#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N = 30;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> comb;
    bool b[N];
    vector<vector<int>> combine(int n, int k) {
        combine1(n,k,1);
        return res;
    }

    void combine1(int n, int k, int stIdx){
        if(k == 0){
            res.push_back(comb);
            return ;
        }
        for(int i = stIdx; i <= n - k + 1; i++){
            if(b[i] == false){
                b[i] = true;
                comb.push_back(i);
                combine1(n,k-1,i+1);
                b[i] = false;
                comb.pop_back();
            }
        }
    }
};