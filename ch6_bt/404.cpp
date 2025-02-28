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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        if(root->left!= NULL && root->left->left == NULL && root->left->right == NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        int suml = sumOfLeftLeaves(root->left);
        int sum2 = sumOfLeftLeaves(root->right);
        return suml + sum2;
    }
};