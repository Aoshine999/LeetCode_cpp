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
    int maxDepth = INT32_MIN;
    int res = 0;
    void traversal(TreeNode *root, int depth){
        if(root->left == NULL && root->right == NULL){
            if(depth > maxDepth){
                maxDepth = depth;
                res = root->val;
            }
            return;
        }
        if(root->left){
            depth++;
            traversal(root->left,depth);
            depth--;
        }
        if(root->right){
            depth++;
            traversal(root->right,depth);
            depth--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        traversal(root,depth);
        return res;
    }
};