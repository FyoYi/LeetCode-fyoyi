// 题目：https://leetcode.cn/problems/merge-two-sorted-lists

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *newlist = new ListNode;
    ListNode *head = newlist;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    while (list1 != nullptr && list2 != nullptr) {

      if (list1->val <= list2->val) {
        ListNode *p = new ListNode(list1->val, nullptr);
        list1 = list1->next;
        head->next = p;
        head = p;
      } else {
        ListNode *p = new ListNode(list2->val, nullptr);
        list2 = list2->next;
        head->next = p;
        head = p;
      }
    }

    if (list1 != nullptr)
      head->next = list1;
    else
      head->next = list2;

    return newlist->next;
  }
};