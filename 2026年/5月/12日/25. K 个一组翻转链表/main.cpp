// 题目：https://leetcode.cn/problems/reverse-nodes-in-k-group

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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *t = head;
    int size = 0;
    while (t != nullptr) {
      size++;
      t = t->next;
    }
    int time = size / k;
    ListNode *node[k];
    ListNode *top = head;
    ListNode *d = new ListNode(0, head);
    ListNode *output;
    for (int i = 0; i < time; i++) {
      for (int a = 0; a < k; a++) {
        node[a] = top;
        top = top->next;
      }
      d->next = node[k - 1];
      node[0]->next = top;
      for (int a = 1; a < k; a++) {
        node[a]->next = node[a - 1];
      }
      if (i == 0) {
        output = node[k - 1];
      }
      d = node[0];
    }
    return output;
  }
};