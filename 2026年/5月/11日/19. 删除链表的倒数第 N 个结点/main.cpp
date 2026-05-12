// 题目：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p1 = head;
    int num = 0;
    while (p1 != nullptr) {
      p1 = p1->next;
      num++;
    }
    ListNode *p2 = head;
    if (num == 1)
      return nullptr;
    if (n == 1) {
      while (p2->next->next != nullptr)
        p2 = p2->next;
      p2->next = nullptr;
      return head;
    }
    if (n == num) {
      return p2->next;
    } else {
      for (int i = 0; i < num - n - 1; i++) {
        p2 = p2->next;
      }
      p2->next = p2->next->next;
      return head;
    }

    return head;
  }
};