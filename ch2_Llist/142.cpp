#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fa = head;
        ListNode *sl = head;
        while (fa!=nullptr && fa->next!=nullptr)
        {
            /* code */
            sl = sl->next;
            fa = fa->next->next;
            if(sl == fa){
                ListNode *f1 = fa;
                ListNode *f2 = head;
                while(f1 != f2){
                    f1 = f1->next;
                    f2 = f2->next;
                }
                return f1;
            }
        }
        return NULL;
    }
};