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
    bool isSymmetric(TreeNode* root){
        return isSame(root->left,root->right);
    }
    bool isSame(TreeNode *left,TreeNode *right){
        // 首先排除空节点的情况
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val) return false;
        bool left1 = isSame(left->left,right->right);
        bool right1 = isSame(left->right,right->left);
        return left1 && right1;
    }

    bool isSymmetric1(TreeNode *root){
        if(root == NULL) return true;
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode *left = st.top(); st.pop();
            TreeNode *right = st.top(); st.pop();
            if(!left && !right) continue;
            if(!left || !right || left->val != right->val) return false;

            st.push(left->left);
            st.push(right->right);
            st.push(left->right);
            st.push(right->left);
        }

        return true;
    }
};