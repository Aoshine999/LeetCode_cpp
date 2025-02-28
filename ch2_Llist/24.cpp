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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *prev = dummyNode;
        ListNode *cur = head;
        while(cur!=nullptr && cur->next!=nullptr){
            ListNode *tmp = cur->next;
            prev->next = tmp;
            cur->next = cur->next->next;
            tmp->next = cur;
            prev = cur;
            cur = cur->next;
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};