//
// Created by ft on 2018/9/11.
//
/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 说明：
 * 给定的 n 保证是有效的。
 * 进阶：
 * 你能尝试使用一趟扫描实现吗？
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == nullptr)
            return head;

        ListNode * fast = head;
        ListNode * slow = head;

        for (int i = 0; i < n; ++i) // n保证是有效的
            fast = fast->next;

        if(fast== nullptr)
            return head->next;

        while (fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
