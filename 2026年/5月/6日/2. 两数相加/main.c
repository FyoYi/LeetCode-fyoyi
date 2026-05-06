// 题目：https://leetcode.cn/problems/add-two-numbers

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
  l3->val = 1;
  l3->next = NULL;

  struct ListNode *tail = l3;

  int add = 0;
  int sum = 0;

  while (l1 != NULL || l2 != NULL) {

    if (l1 != NULL && l2 != NULL) {
      sum = l1->val + l2->val + add;
      l1 = l1->next;
      l2 = l2->next;
    } else if (l1 != NULL && l2 == NULL) {
      sum = l1->val + add;
      l1 = l1->next;
    } else {
      sum = l2->val + add;
      l2 = l2->next;
    }

    if (sum > 9) {
      sum = sum - 10;
      add = 1;
    } else {
      add = 0;
    }

    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = sum;
    p->next = NULL;

    tail->next = p;
    tail = p;
  }

  if (add == 1) {
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = 1;
    p->next = NULL;

    tail->next = p;
    tail = p;
  }

  return l3->next;
}

