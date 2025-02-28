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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        return ld > rd ? ld + 1 : rd + 1;
    }
    int maxDepth1(TreeNode* root){
        queue<TreeNode *> que;
        int depth = 0;
        if(root != nullptr) que.push(root);
        while (!que.empty())
        {
            /* code */
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
    int minDepth(TreeNode* root){
        queue<TreeNode *> que;
        int depth = 0;
        if(root != nullptr) que.push(root);
        while (!que.empty())
        {
            depth++;
            /* code */
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode *node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(!node->left && !node->right) return depth;
            }
            
        }
        return depth;
    }
    int minDepth1(TreeNode *root){
        if(root == NULL) return 0;
        else{
            int leftDep = minDepth1(root->left);
            int righDep = minDepth1(root->right);
            if(!root->left && root->right) return 1 + righDep;
            if(root->left && !root->right) return 1 + leftDep;
            return 1 + min(leftDep,righDep);
        }
    }
};