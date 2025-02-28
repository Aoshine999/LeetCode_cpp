#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i < k; i++){
            myQueue.push(nums[i]);
        }
        res.push_back(myQueue.front());
        for(int i = k; i < nums.size(); i++){
            myQueue.pop(nums[i-k]);
            myQueue.push(nums[i]);
            res.push_back(myQueue.front());
        }
        return res;
    }
private:
    MyQueue myQueue;
};
class MyQueue{
private:
    deque<int> squ;
public:
    void push(int value){
        while(!squ.empty() && value > squ.back()){
            squ.pop_back();
        }
        squ.push_back(value);
    }
    void pop(int value){
        if(!squ.empty() && squ.front() == value){
            squ.pop_front();
        }
    }
    int front(){
        return squ.front();
    }
};