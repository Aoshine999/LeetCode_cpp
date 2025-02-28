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
        int largestRectangleArea(vector<int>& heights) {
            vector<int> lHeight(heights.size());
            vector<int> rHeight(heights.size());
            
            lHeight[0] = -1;
            for(int i = 1; i < heights.size(); i++){
                int t = i - 1;
                while(t >= 0 && heights[t] >= heights[i]) t = lHeight[t];
                lHeight[i] = t;
            }
            int size = heights.size();
            rHeight[size - 1] = size;

            for(int i = size - 2; i >= 0; i--){
                int t = i + 1;

                while(t < size && heights[t] >= heights[i]) t = rHeight[t];
                rHeight[i] = t;
            }

            int  res = 0;

            for(int i = 0; i < size; i++){
                int sum = heights[i] * (rHeight[i] - lHeight[i] - 1);
                res = max(sum,res);
            }
            return res;
        }

        int largestRectangleArea1(vector<int>& heights) {
            stack<int> st;
            heights.insert(heights.begin(),0);
            heights.push_back(0);
            int sum = 0;

            st.push(0);
            for(int i = 1; i < heights.size(); i++){
                if(heights[st.top()] < heights[i]){
                    st.push(i);
                }else if(heights[st.top()] == heights[i]){
                    st.pop();
                    st.push(i);
                }else{
                    while(!st.empty() && heights[st.top()] > heights[i]){
                        int mid = heights[st.top()];
                        st.pop();
                        if(!st.empty()){
                            int l = st.top();
                            int r = i;
                            sum = max(sum, (r - l - 1) * mid);
                        }
                    }
                    st.push(i);
                }
            }

            return sum;
        }
};
