#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> res;

template <typename T>
struct BiTree
{
    /* data */
    T val;
    BiTree *left;
    BiTree *right;
    BiTree(T x): val(x), left(nullptr), right(nullptr){}
};

vector<vector<int>> Level_Traversal(BiTree<int> *root){
    queue<BiTree<int>*> que;
    vector<vector<int>> Level_Order;
    if(root != nullptr) que.push(root);
    while (!que.empty())
    {
        /* code */
        int size = que.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            BiTree<int> *node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            vec.push_back(node->val);
        }
        Level_Order.push_back(vec);
    }
    return Level_Order;
}

class Solution{
public:
    void Level_Traversal(BiTree<int> *root, vector<vector<int>> &res, int depth){
        if(root == nullptr) return;
        if(res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        Level_Traversal(root->left,res,depth+1);
        Level_Traversal(root->right,res,depth+1);
    }
    vector<vector<int>> Level_Order_Traversal(BiTree<int> *root){
        vector<vector<int>> res;
        int depth = 0;
        Level_Traversal(root,res,depth);
        return res;
    }
};


