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
struct BiTree{
    T val;
    BiTree *left;
    BiTree *right;
    BiTree(T x): val(x), left(nullptr), right(nullptr){}
};


void preTraversal(BiTree<int> *node){
    if(node==NULL) return;
    else{
        //do
        res.push_back(node->val);
        preTraversal(node->left);
        preTraversal(node->right);
    }
}
void inTraversal(BiTree<int> *node){
    if(node == nullptr) return;
    else{
        inTraversal(node->left);
        //do
        res.push_back(node->val);
        inTraversal(node->right);
    }
}
void postTraversal(BiTree<int> *node){
    if(node==nullptr) return;
    else{
        inTraversal(node->left);
        inTraversal(node->right);
        // do 
        res.push_back(node->val);
    }
}


void preOrderTraversal(BiTree<int> *root){
    stack<BiTree<int> *> st;
    if(root == NULL) return;
    st.push(root);
    while (!st.empty())
    {
        /* code */
        BiTree<int>* node = st.top();
        st.pop();
        res.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
}


void InOrderTraversal(BiTree<int> *root){
    stack<BiTree<int>*> st;
    BiTree<int>* cur = root;
    while(cur != NULL || !st.empty()){
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }else{
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
}


void PostOrderTraversal(BiTree<int> *root){
    stack<BiTree<int> *> st;
    if(root == NULL) return;
    st.push(root);
    while (!st.empty())
    {
        /* code */
        BiTree<int>* node = st.top();
        st.pop();
        res.push_back(node->val);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    reverse(res.begin(),res.end());
}


void InOrderTraversal1(BiTree<int> *root){
    stack<BiTree<int> *> st;
    if(root != nullptr) st.push(root);
    while (!st.empty())
    {
        /* code */
        BiTree<int> *node = st.top();
        if(node != nullptr){
            st.pop();
            if(node->right) st.push(node->right);

            st.push(node);
            st.push(nullptr);

            if(node->left) st.push(node->left);
        }else{
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }
}

void PreOrderTraversal1(BiTree<int> *root){
    stack<BiTree<int> *> st;
    if(root != nullptr) st.push(root);
    while (!st.empty())
    {
        /* code */
        BiTree<int> *node = st.top();
        if(node != nullptr){
            st.pop();
            if(node->right) st.push(node->right);

            if(node->left) st.push(node->left);

            st.push(node);
            st.push(nullptr);
        }else{
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }
}

void PostOrderTraversal1(BiTree<int> *root){
        stack<BiTree<int> *> st;
    if(root != nullptr) st.push(root);
    while (!st.empty())
    {
        /* code */
        BiTree<int> *node = st.top();
        if(node != nullptr){
            st.pop();

            st.push(node);
            st.push(nullptr);
            if(node->right) st.push(node->right);

            if(node->left) st.push(node->left);


        }else{
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }
}
