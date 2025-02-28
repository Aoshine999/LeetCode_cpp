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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *node = new TreeNode();
        if(nums.size() == 1){
            node->val = nums[0];
            return node;
        }

        int maxVal = 0;
        int maxValInd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxVal){
                maxValInd = i;
                maxVal = nums[i];
            }
        }

        node->val = maxVal;

        if(maxValInd > 0){
            vector<int> newvc(nums.begin(), nums.begin() + maxValInd);
            node->left = constructMaximumBinaryTree(newvc);
        }

        if(maxValInd < (nums.size() - 1)){
            vector<int> newvc(nums.begin() + maxValInd + 1,nums.end());
            node->right = constructMaximumBinaryTree(newvc);
        }

        return node;
    }
};