#include<iostream>
using namespace std;
struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur;

        while(head!=nullptr && head->val == val){
            ListNode *tmp = head;
            head = head -> next;
            delete tmp;
        }

        cur = head;
        while(cur != nullptr && cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }

        return head;
    }
};

int main(){

    return 0;
}