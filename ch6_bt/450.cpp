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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
                TreeNode *cur = root->left;
                delete root;
                return cur;
            }else if(root->left == NULL && root->right != NULL){
                TreeNode *cur = root->right;
                delete root;
                return cur;
            }else{
                TreeNode *cur = root->right;
                while(cur->left) cur = cur->left;

                cur->left = root->left;
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};