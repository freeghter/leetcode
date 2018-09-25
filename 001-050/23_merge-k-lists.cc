//
// Created by ft on 2018/9/12.
//
/**
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * p = nullptr;
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        if(lists.empty())
            return nullptr;
        do{
            int index = 0;
            p = nullptr;
            for(int i = 0; i < lists.size(); ++i){
                if(p == nullptr || (lists[i] != nullptr && (p->val > lists[i]->val))) {
                    p = lists[i];
                    index = i;
                }
            }
            if(lists[index] == nullptr)
                break;
            p = lists[index];
            lists[index] = lists[index]->next;
            if(head == nullptr){
                head = p;
                tail = head;
            }else {
                tail->next = p;
                tail = tail->next;
            }
        }while (p != nullptr);
        return head;
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
    vector<int> v;
    vector<ListNode*> lists;

    v={1,4,5};
    lists.push_back(make_list(v));
    v={1,3,4};
    lists.push_back(make_list(v));
    v={2, 6};
    lists.push_back(make_list(v));

    Solution s;
    auto head = s.mergeKLists(lists);

    for (ListNode * p = head;  p ; p=p->next)
        cout << p->val << " ";

    return 0;
}