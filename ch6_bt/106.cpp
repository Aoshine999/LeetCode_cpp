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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return NULL;

        int rv = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rv);

        if(postorder.size() == 1) return root;

        int delimiterIdx;
        for(delimiterIdx = 0; delimiterIdx < inorder.size(); delimiterIdx++){
            if(inorder[delimiterIdx] == rv) break;
        } 

        vector<int> leftInOrd(inorder.begin(),inorder.begin() + delimiterIdx);
        vector<int> rightInOrd(inorder.begin() + delimiterIdx + 1,inorder.end());

        postorder.pop_back();

        vector<int> leftPoOrd(postorder.begin(), postorder.begin() + leftInOrd.size());
        vector<int> rightPoOrd(postorder.begin() + leftInOrd.size(), postorder.end());

        root->left = buildTree(leftInOrd,leftPoOrd);

        root->right = buildTree(rightInOrd,rightPoOrd);

        return root;
    }
};