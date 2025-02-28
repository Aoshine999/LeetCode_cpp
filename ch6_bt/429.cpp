#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        while (!que.empty())
        {
            /* code */
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                Node *node = que.front();
                que.pop();
                vec.push_back(node->val);
                for(int j = 0; j < node->children.size(); j++){
                    que.push(node->children[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};