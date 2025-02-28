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
    bool flag = true;
    bool isValidBST(TreeNode* root) {
        isBST(root);
        return flag;
    }
    void isBST(TreeNode* root){
        if(root == NULL) return;

        isBST(root->left);
        if(prev == NULL){
            prev = root;
        }else{
            if(prev->val < root->val){
                prev = root;
            }else{
                flag = false;
            }
        }
        isBST(root->right);

    }
};

int main(){



    return 0;
}