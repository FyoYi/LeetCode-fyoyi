// 问题：https://leetcode.cn/problems/4sum

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int aaa(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int **fourSum(int *nums, int numsSize, int target, int *returnSize,
              int **returnColumnSizes) {
  int **output = (int **)malloc(10000 * sizeof(int *));
  *returnColumnSizes = malloc(10000 * sizeof(int));
  *returnSize = 0;
  qsort(nums, numsSize, sizeof(int), aaa);
  long long add = 0;
  for (int x = 0; x < numsSize - 3; x++) {
    if (x > 0) {
      if (nums[x] == nums[x - 1])
        goto flag1;
    }
    for (int y = x + 1; y < numsSize - 2; y++) {
      if (y > x + 1) {
        if (nums[y] == nums[y - 1])
          goto flag2;
      }
      int left = y + 1;
      int right = numsSize - 1;
      while (left < right) {
        add = (long long)nums[x] + nums[y] + nums[left] + nums[right];
        if (add == target) {
          output[*returnSize] = malloc(4 * sizeof(int));
          output[*returnSize][0] = nums[x];
          output[*returnSize][1] = nums[y];
          output[*returnSize][2] = nums[left];
          output[*returnSize][3] = nums[right];
          (*returnColumnSizes)[*returnSize] = 4;
          (*returnSize)++;
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;
          left++;
          right--;
        }
        if (add > target)
          right--;
        if (add < target)
          left++;
      }
    flag2:
    }
  flag1:
  }
  return output;
}