// 问题：https://leetcode.cn/problems/letter-combinations-of-a-phone-number

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode {
  char value;
  struct TreeNode *son[4];
} TreeNode;

char **letterCombinations(char *digits, int *returnSize) {
  char **output = (char **)malloc((3 * 3 * 4 * 4) * sizeof(char *));
  TreeNode *T = (TreeNode *)malloc(sizeof(TreeNode));
  T->value = '\0';
  for (int i = 0; i < 4; i++)
    T->son[i] = NULL;

  char *map[] = {"",    "",    "abc",  "def", "ghi",
                 "jkl", "mno", "pqrs", "tuv", "wxyz"};

  TreeNode *N = T;
  int size = strlen(digits);
  for (int x = 0; x < size; x++) {
    int num = digits[x] - '0';
    for (int y = 0; y < strlen(map[num]); y++) {
      TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
      p->value = map[num][y];
      for (int i = 0; i < 4; i++)
        p->son[i] = NULL;
      N->son[y] = p;
    }
  }

  return output;
}