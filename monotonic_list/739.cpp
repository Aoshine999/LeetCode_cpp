#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

class Solution {
    private:
    stack<int> st;
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> res(temperatures.size(), 0);
            caldaTemp(temperatures,res);
            return res;
        }
        void caldaTemp(vector<int>& temperature,vector<int>& res){
            st.push(0);
            for(int i = 1; i < temperature.size(); i++){
                if(temperature[st.top()] < temperature[i]){
                    while(!st.empty() && temperature[st.top()] < temperature[i]){
                        res[st.top()] = i - st.top();
                        st.pop();
                    }
                    st.push(i);
                }else{
                    st.push(i);
                }
            }
        }
};


