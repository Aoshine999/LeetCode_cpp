#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int res;
        while (in.size() > 1)
        {
            res = in.front();
            out.push(res);
            in.pop();
        }
        res = in.front();
        int res1 = res;
        in.pop();
        while(!out.empty()){
            res = out.front();
            in.push(res);
            out.pop();
        }
        return res1;
    }
    
    int top() {
        int res = this->pop();
        in.push(res);
        return res;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    queue<int> in;
    queue<int> out;
};
int main(){
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top();
}