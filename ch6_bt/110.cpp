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
    bool isBalanced(TreeNode* root) {
        if(Depth(root) == -1) return false;
        return true;
    }

    int Depth(TreeNode* root){
        if(root == NULL) return 0;
        else{
            int ld = Depth(root->left);
            int rd = Depth(root->right);
            if(ld == -1 || rd == -1) return -1;
            return abs(ld - rd) > 1 ? -1 : max(ld,rd) + 1;
        } 
    }
};
