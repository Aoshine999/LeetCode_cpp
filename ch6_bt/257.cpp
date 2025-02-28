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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root,path,res);
        return res;
    }

    void traversal(TreeNode *node,vector<int> &path, vector<string> &result){
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL){
            string s = "";
            for(int i = 0; i < path.size() - 1; i++){
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size()-1]);
            result.push_back(s);
            return;
        }

        if(node->left){
            traversal(node->left,path,result);
            path.pop_back();
        }

        if(node->right){
            traversal(node->right,path,result);
        }
    }
};

int main(){
    Solution s;
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(2);
    TreeNode *a3 = new TreeNode(3);
    TreeNode *a4 = new TreeNode(5);
    a1->left = a2;
    a1->right = a3;
    a2->right = a4;
    s.binaryTreePaths(a1);
}