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
    vector<int> nodes_val;
    vector<int> sub_val;
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        for(int i = nodes_val.size() - 1; i > 0; i--){
            sub_val.push_back(nodes_val[i] - nodes_val[i-1]);
        }
        int minval = INT32_MAX;
        for(int val : sub_val){
            if(val < minval){
                minval = val;
            }
        }

        return minval;
    }
    void traversal(TreeNode *root){
        if(root == NULL) return;
        traversal(root->left);
        nodes_val.push_back(root->val);
        traversal(root->right);
    }
};



