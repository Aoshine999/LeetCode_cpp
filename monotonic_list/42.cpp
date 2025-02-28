#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> lHeight(height.size(),0);
            vector<int> rHeight(height.size(),0);

            int size = height.size();

            lHeight[0] = height[0];

            for(int i = 1; i < size - 1; i++){
                lHeight[i] = max(height[i],lHeight[i-1]);
            }

            rHeight[size - 1] = height[size - 1];
            for(int i = height.size() - 2; i > 0; i--){
                rHeight[i] = max(height[i],rHeight[i+1]);
            }
            int sum = 0;
            for(int i = 1; i < size - 1; i++){
                int count = min(lHeight[i],rHeight[i]) - height[i];
                if(count > 0) sum += count;
            }

            return sum;
        }
};


class Solution1 {
    public:
        int trap(vector<int>& height) {
            if(height.size() <= 2) return 0;
            stack<int> st;
            st.push(0);

            int sum = 0;
            for(int i = 1; i < height.size(); i++){
                if(height[i] < height[st.top()]){
                    st.push(i);
                } else if(height[i] == height[st.top()]){
                    st.pop();
                    st.push(i);
                }else{
                    while(!st.empty() && height[i] > height[st.top()]){
                        int mid = st.top();
                        st.pop();
                        if(!st.empty()){
                            int h = min(height[i],height[st.top()]) - height[mid];
                            int w = i - st.top() - 1;
                            sum += h * w;
                        }
                    }
                    st.push(i);
                }
            }

            return sum;
        }
};