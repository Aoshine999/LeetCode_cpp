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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l=head,*r=head;
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *tmp = dummyNode;
        int i = 1;
        while(i!=n){
            r = r->next;
            i++;
        }
        while(r!=nullptr && r->next!=nullptr){
            r = r->next;
            l = l->next;
            tmp = tmp->next;
        }
        tmp->next = l->next;
        delete l;
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};