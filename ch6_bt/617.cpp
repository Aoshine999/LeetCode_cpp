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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *node;
        if(root1 == NULL && root2 != NULL){
            node = new TreeNode(root2->val);
            node->left = mergeTrees(NULL,root2->left);
            node->right = mergeTrees(NULL,root2->right);
            return node;
        }
        if(root1 != NULL && root2 == NULL){
            node = new TreeNode(root1->val);
            node->left = mergeTrees(root1->left,NULL);
            node->right = mergeTrees(root1->right,NULL);
            return node;
        }
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }

        node = new TreeNode(root1->val + root2->val);
        node->left = mergeTrees(root1->left,root2->left);
        node->right = mergeTrees(root1->right,root2->right);

        return node;
    }
};