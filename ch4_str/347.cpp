#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    class myComparion{
        public:
            bool operator()(const pair<int,int>& num1,const pair<int,int>& num2){
                return num1.second > num2.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,myComparion> pri_que;

        for(unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        vector<int> res;
        while(!pri_que.empty()){
            res.push_back(pri_que.top().first);
            pri_que.pop();
        }

        return res;
    }
};