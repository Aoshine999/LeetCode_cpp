#include<iostream>
using namespace std;

class MyLinkedList {

public:
    struct ListNode
    {
        /* data */
        int val;
        ListNode *next;
        ListNode(int val) : val(val),next(nullptr) {}
    };
    
    MyLinkedList() {
        size = 0;
        dummyHead = new ListNode(0);        
    }
    
    int get(int index) {
        if(index < 0 || index + 1 > size) return -1;
        int i = 0;
        ListNode *cur = dummyHead;
        while(cur->next!=nullptr){
            if(i == index){
                return cur->next->val;
            }
            cur = cur->next;
            i++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode *cur = new ListNode(val);
        cur->next = dummyHead->next;
        dummyHead->next = cur;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode *node = new ListNode(val);
        ListNode *cur = dummyHead;
        while(cur->next!=nullptr) cur = cur->next;
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size) return;
        if (index == size){
            /* code */
            addAtTail(val);
            return;
        }
        
        int i = 0;
        ListNode *cur = dummyHead;
        while(cur->next!=nullptr){
            if(i==index){
                ListNode *tmp = new ListNode(val);
                tmp->next = cur->next;
                cur->next = tmp;
                size++;
                return;
            }
            i++;
            cur = cur->next;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index + 1 > size) return;
        int i = 0;
        ListNode *cur = dummyHead;
        while (cur->next!=nullptr){
            if(i==index){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                size--;
                return;
            }
            i++;
            cur = cur->next;
        }
    }

    void show(){
        ListNode *cur = dummyHead;
        cout << size << endl;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur -> next;
        }
        
    }
private:
    int size;
    ListNode *dummyHead;
};
int main(){
    MyLinkedList m;
    m.addAtHead(7);
    m.addAtHead(2);
    m.addAtHead(1);
    //m.show();
    m.addAtIndex(3,0);
    m.show();
    m.deleteAtIndex(2);
    cout << endl;
    m.show();
    // m.addAtHead(6);
    // m.addAtTail(4);
    // m.show();
    //cout << m.get(1) << endl;
    //cout << m.get(1);
}