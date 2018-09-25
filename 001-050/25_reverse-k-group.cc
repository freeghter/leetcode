//
// Created by ft on 2018/9/13.
//
/**
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
 * 示例 :
 * 给定这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 说明 :
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;

        int i = 0;
        for (auto p=head, t=head; p != nullptr; p = t) {
            for (i = 1; i < k && t != nullptr; ++i)
                t = t->next;

            if(t != nullptr) {
                ListNode * p_tail = t;
                t = t->next;
                p_tail->next = nullptr;
            }
            else if(i < k || (i == k && t == nullptr)) {
                if(new_head == nullptr)
                    return p;
                tail->next = p;
                break;
            }

            p = reverse(p);
            if(new_head == nullptr) {
                new_head = p;
            }else{
                tail ->next =p;
            }
            for (tail = p;  tail->next != nullptr; tail = tail->next);
        }
        return new_head;
    }

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

private:
    ListNode * reverse(ListNode * head){
        ListNode * h = nullptr;
        for (auto p = head; p != nullptr ;) {
            ListNode * t = p;
            p = p->next;
            t->next = h;
            h = t;
        }
        return h;
    }
};

int main(int argc, char * argv[]){
    Solution s;
    vector<int> v={1,2};
    auto l = s.make_list(v);

    auto r = s.reverseKGroup(l, 2);
    for (auto p=r;p!= nullptr; p=p->next){
        cout << p->val << " ";
    }
    return 0;
}
