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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        if(root->val < low){
            DeletNode(root->left);
            TreeNode* tmp = root;
            root = root->right;
            delete tmp;
            return trimBST(root,low,high);
            
        }else if(root->val > high){
            DeletNode(root->right);
            TreeNode* tmp = root;
            root = root->left;
            delete tmp;
            return trimBST(root,low,high);
        }

        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);

        return root;
    }

    void DeletNode(TreeNode *node){
        if(node == NULL) return ;
        DeletNode(node->left);
        DeletNode(node->right);
        delete node;
    }
    void Traverse(TreeNode *node){
        if(node == NULL) return ;
        cout << node->val << " ";
        Traverse(node->left);
        Traverse(node->right);
    }
};

int main(){
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(2);
    a1->right = a2;
    Solution s;
    TreeNode *a = s.trimBST(a1,2,4);
    s.Traverse(a);
    return 0;
}