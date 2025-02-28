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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        TreeNode *node = root;
        while(node != NULL){
            if(node->val == val) return node;

            if(node->val > val){
                node = node->left;
            }else{
                node = node->right;
            } 
        }

        return NULL;
    }
};

int main(){
    TreeNode *a1 = new TreeNode(4);
    TreeNode *a2 = new TreeNode(2);
    TreeNode *a3 = new TreeNode(7);
    TreeNode *a4 = new TreeNode(1);
    TreeNode *a5 = new TreeNode(3);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    Solution s;
    s.searchBST(a1,2);
}