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
    vector<int> res;
    int maxCount = 0;
    int count = 0;
    TreeNode* prev = NULL;
    vector<int> findMode(TreeNode* root) {
        find(root);
        return res;
    }

    void find(TreeNode* root){
        if(root == NULL) return;
        find(root->left);
        if(prev == NULL){
            prev = root;
            count = 1;
        }else{
            if(prev->val == root->val){
                prev = root;
                count++;
            }else{
                count = 1;
                prev = root;
            }
        }

        if(count == maxCount){
            res.push_back(root->val);
        }

        if(count > maxCount){
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        }
        find(root->right);
    }
};