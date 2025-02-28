#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        out.push(res);
        return res;
    }
    
    bool empty() {
        return out.empty() && in.empty();
    }
private:
    stack<int> in;
    stack<int> out;
};
