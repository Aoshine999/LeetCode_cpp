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
    vector<vector<int>> Level_Traversal(TreeNode *root){
    queue<TreeNode*> que;
    vector<vector<int>> Level_Order;
    if(root != nullptr) que.push(root);
    while (!que.empty())
    {
        /* code */
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode *node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            vec.push_back(node->val);
        }
        Level_Order.push_back(vec);
    }
    return Level_Order;
}
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> vec = Level_Traversal(root);
        vector<int> res;
        for(int i = 0; i < vec.size(); i++){
            res.push_back(vec[i][vec[i].size()-1]);
        }
        return res;
    }
};