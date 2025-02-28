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
    TreeNode *prev = NULL;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return NULL;
        root->right = convertBST(root->right);
        if(prev != NULL){
            root->val += prev->val;
        }
        prev = root;
        root->left = convertBST(root->left);

        return root;
    }
};