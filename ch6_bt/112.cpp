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
    bool flag = false;
    int res = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        return flag;
    }


    void hasTrue(TreeNode *root, int targetSum){
        if(root->left == NULL && root->right == NULL){
            if(res + root->val == targetSum){
                flag = true;
            }
        }
        res += root->val;
        if(root->left){
            hasPathSum(root->left,targetSum);
            res -= root->left->val;
        }
        if(root->right){
            hasPathSum(root->right,targetSum);
            res -= root->right->val;
        }
    }
};