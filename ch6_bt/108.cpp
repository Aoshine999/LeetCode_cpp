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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = traversal(nums,0,nums.size()-1);
        return root;
    }

    TreeNode* traversal(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = traversal(nums,low,mid-1);
        node->right = traversal(nums,mid+1,high);
        return node;
    }
};