// 问题：https://leetcode.cn/problems/3sum-closest

int asd(int input) {
  if (input >= 0)
    return input;
  return -input;
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int threeSumClosest(int *nums, int numsSize, int target) {

  qsort(nums, numsSize, sizeof(int), cmp);

  int add = 0;
  int d = INT_MIN;
  int min = INT_MAX;
  int output = 0;
  for (int i = 0; i < numsSize - 2; i++) {
    int left = i + 1;
    int right = numsSize - 1;
    while (left < right) {
      add = nums[i] + nums[left] + nums[right];
      d = asd(add - target);
      if (add > target)
        right--;
      if (add < target)
        left++;
      if (add == target)
        return add;
      if (min > d) {
        min = d;
        output = add;
      }
    }
  }
  return output;
}