//
// Created by ft on 2018/8/29.
//
/**
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。
 * 将两数相加返回一个新的链表。
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 * 示例：
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        int flag = 0;
        for (ListNode * p1 = l1, *p2 = l2; p1 != nullptr || p2 != nullptr || flag; ) {
            int sum = 0;
            if(p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2 != nullptr) {
                sum += p2->val;
                p2 = p2->next;
            }

            auto p = new ListNode((sum + flag) % 10);
            if(head == nullptr) {
                head = p;
                tail = p;
            }else {
                tail->next = p;
                tail = p;
            }
            sum += flag;
            sum >= 10 ? flag = 1: flag = 0;
        }

        return head;
    }
};

int main(int argc, char * argv[]){
    ListNode * p1 = nullptr;
    ListNode * p2 = nullptr;

    vector<int> v1={1};
    for (auto i: v1) {
        auto p = new ListNode(i);
        p->next = p1;
        p1 = p;
    }

    vector<int> v2={9,9};
    for (auto i: v2) {
        auto p = new ListNode(i);
        p->next = p2;
        p2 = p;
    }

    Solution s;
    auto p = s.addTwoNumbers(p1, p2);

    while (p){
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}