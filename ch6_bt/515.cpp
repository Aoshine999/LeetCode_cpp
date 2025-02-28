#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> que;
        vector<int> res;
        if(root != nullptr) que.push(root);
        while (!que.empty())
        {
            /* code */
            int size = que.size();
            int num = INT32_MIN;
            for(int i = 0; i < size; i++){
                TreeNode *node = que.front();
                que.pop();
                num = num > node->val? num : node->val;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
           res.push_back(num);
        }
        return res;      
    }
};