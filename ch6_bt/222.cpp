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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        TreeNode *left = root->left,*right = root->right;
        int lDep = 0,rDep = 0;
        while(left != NULL){
            left = left->left;
            lDep++;
        }
        while(rDep != NULL){
            right = right->right;
            rDep++;
        }
        if(lDep == rDep) return (2<<lDep) + 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};