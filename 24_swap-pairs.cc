//
// Created by ft on 2018/9/13.
//
/**
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 示例:
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 说明:
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr)
            return head;

        ListNode * new_head = nullptr;
        ListNode * tail = nullptr;
        for(auto p = head; p != nullptr;){
            auto p1 = p;
            auto p2 = p->next;
            p = p->next == nullptr ? nullptr : p->next->next;

            if(p2 == nullptr)
                p2 = p1;
            else
                p2->next = p1;
            p1->next = nullptr;
            if(new_head == nullptr){
                new_head = p2;
                tail = new_head->next;
            }else {
                tail->next = p2;
                tail = tail->next != nullptr ? tail->next->next : tail->next;
            }
        }
        return new_head;
    }
};

ListNode * make_list(vector<int> v){
    ListNode * head = nullptr;
    ListNode * tail = nullptr;
    for(int i: v){
        if(head == nullptr){
            head = new ListNode(i);
            tail = head;
        }else{
            tail->next = new ListNode(i);
            tail = tail->next;
        }
    }
    return head;
}

int main(int argc, char *argv[]) {
    vector<int> v = {};
    auto l = make_list(v);
    Solution s;
    auto r = s.swapPairs(l);
    for (auto p = r; p ; p=p->next) {
        cout << p->val << " ";
    }
    return 0;
}