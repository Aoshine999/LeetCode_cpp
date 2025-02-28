#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            vector<int> arr(10e4 + 10,-1);
            generateEle(arr,st,nums2);
            vector<int> res(nums1.size(),0);
            for(int i = 0; i < nums1.size(); i++){
                res[i] = arr[nums1[i]];
            }

            return res;
        }

        void generateEle(vector<int>& arr,stack<int>& st,vector<int>& nums2){
            for(int i = 0; i < nums2.size(); i++){
                if(st.empty()){
                    st.push(i);
                } else if(nums2[i] <= nums2[st.top()]){
                    st.push(i);
                } else{
                    while(!st.empty() && nums2[st.top()] < nums2[i]){
                        arr[nums2[st.top()]] = nums2[i];
                        st.pop(); 
                    }
                    st.push(i);
                }
            }
        }

        vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int,int> idx;
            stack<int> st;
            vector<int> ans(nums1.size(), -1);
            for(int i = 0; i < nums1.size(); i++){
                idx[nums1[i]] = i;
            }

            for(int i = 0; i < nums2.size(); i++){
                if(st.empty()){
                    st.push(i);
                }else if(nums2[i] <= nums2[st.top()]){
                    st.push(i);
                }else{
                    while(!st.empty() && nums2[st.top()] < nums2[i]){
                        if(idx.count(nums2[st.top()]) > 0){
                            int x = nums2[st.top()];
                            ans[idx[x]] = nums2[i];
                        }
                        st.pop();
                    }
                    st.push(i);
                }
            }

            return ans;
        }
};

