// 题目：https://leetcode.cn/problems/merge-k-sorted-lists

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    std::vector<int> arr;

    for (auto node : lists) {
      while (node != nullptr) {
        arr.push_back(node->val);
        node = node->next;
      }
    }

    std::sort(arr.begin(), arr.end());
    ListNode *p = new ListNode;
    ListNode *h = p;
    for (auto i : arr) {
      h->next = new ListNode(i);
      h = h->next;
    }
    return p->next;
  }
};