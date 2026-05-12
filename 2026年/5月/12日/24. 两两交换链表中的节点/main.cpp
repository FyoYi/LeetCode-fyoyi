// 题目：https://leetcode.cn/problems/swap-nodes-in-pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    int size = 0;
    ListNode *h = head;
    while (h != nullptr) {
      size++;
      h = h->next;
    }
    if (size == 0)
      return nullptr;
    if (size == 1)
      return head;
    delete (h);

    ListNode *d = new ListNode(0, head);
    ListNode *o = new ListNode(0);
    int time = size / 2;
    for (int i = 0; i < time; i++) {
      ListNode *node1 = d->next;
      ListNode *node2 = d->next->next;
      d->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      d = node1;
      if (i == 0) {
        o->next = node2;
      }
    }
    return o->next;
  }
};