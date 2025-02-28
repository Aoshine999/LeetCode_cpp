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
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val > p->val && root->val > q->val){
            TreeNode* left = lowestCommonAncestor(root->left,p,q);
            if(left != NULL){
                return left;
            }
        }

        if(root->val < p->val && root->val < q->val){
            TreeNode* right = lowestCommonAncestor(root->right,p,q);
            if(right != NULL){
                return right;
            }
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        TreeNode *node = root;
        while(node != NULL){
            if(node->val > p->val && node->val > q->val){
                node = node->left;
            }else if(node->val < p->val && node->val < q->val){
                node = node->right;
            }else{
                return node;
            }
        }
        return node;
    }
};
