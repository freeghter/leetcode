//
// Created by ft on 2018/9/12.
//
#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        ListNode * head = nullptr, *tail = nullptr, * temp = nullptr;
        while(l1 != nullptr && l2 != nullptr){

            if(l1->val < l2->val){
                temp = l1;
                l1 = l1->next;
            }else{
                temp = l2;
                l2 = l2->next;
            }

            if(head == nullptr) {
                head = temp;
                tail = head;
            }
            tail->next = temp;
            tail = tail->next;
        }
        if(l2 != nullptr)
            tail->next = l2;
        if(l1 != nullptr)
            tail ->next = l1;
        return head;
    }
};

int main(int argc, char * argv[]){
    Solution s;

    return 0;
}
