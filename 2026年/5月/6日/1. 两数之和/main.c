// 题目：https://leetcode.cn/problems/two-sum

#define SIZE 20000

typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

int hash(int value) {
  return (value % SIZE + SIZE) % SIZE;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int *OutPut = (int *)malloc(numsSize * sizeof(int));
  int need;
  int point = 0;
  *returnSize = 2;
  Node *hashTable[SIZE];
  for (int i = 0; i < SIZE; i++) {
    hashTable[i] = NULL;
  }
  for (int i = 0; i < numsSize; i++) {
    need = target - nums[i];
    int index = hash(need);
    Node *p = hashTable[index];
    while (p != NULL) {
      if (p->key == need) {
        OutPut[0] = i;
        OutPut[1] = p->value;
        return OutPut;
      }
      p = p->next;
    }

    int newindex = hash(nums[i]);
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->key = nums[i];
    newNode->value = i;
    newNode->next = hashTable[newindex];

    hashTable[newindex] = newNode;
  }

  return OutPut;
}