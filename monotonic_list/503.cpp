#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;


class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int x = nums.size();

            vector<int> res(x,-1);           
            stack<int> st;        
            for(int i = 0; i < x; i++){
                if(st.empty()){
                    st.push(i);
                } else if(nums[st.top()] >= nums[i]){
                    st.push(i);
                } else{
                    while(!st.empty() && nums[i] > nums[st.top()]){
                        res[st.top()] = nums[i];
                        st.pop();
                    }
                    st.push(i);
                }
            }

            for(int i = 0; i < x; i++){
                if(nums[st.top()] >= nums[i]){
                    //st.push(i);
                } else{
                    while(!st.empty() && nums[i] > nums[st.top()]){
                        res[st.top()] = nums[i];
                        st.pop();
                    }
                }
            }

            return res;
        }
};