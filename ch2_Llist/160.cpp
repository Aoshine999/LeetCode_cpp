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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *la = headA;
        ListNode *lb = headB;
        int i = 0,j = 0;
        while(la!=nullptr){
            i++;
            la = la->next;
        }
        while(lb!=nullptr){
            j++;
            lb = lb->next;
        }
        la = headA;
        lb = headB;
        if(i > j){
            int k = i - j;
            while(k--) la = la->next;
        }
        else{
            int k = j - i;
            while(k--) lb = lb->next;
        }
        while(lb!=nullptr){
            if(la==lb){
                return la;
            }
            lb = lb->next;
            la = la->next;
        }
        return nullptr;
    }
};