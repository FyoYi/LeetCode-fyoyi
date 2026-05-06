// 题目：https://leetcode.cn/problems/longest-substring-without-repeating-characters

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int numsSize = nums1Size + nums2Size;
  int nums[numsSize];
  int point1 = 0;
  int point2 = 0;
  int output = 0;

  for (int i = 0; i < numsSize; i++) {
    if (point1 < nums1Size && point2 < nums2Size) {
      if (nums1[point1] < nums2[point2]) {
        nums[i] = nums1[point1];
        point1++;
      } else if (nums1[point1] > nums2[point2]) {
        nums[i] = nums2[point2];
        point2++;
      } else if (nums1[point1] == nums2[point2]) {
        nums[i] = nums1[point1];
        point1++;
      }
    } else if (point1 == nums1Size && point2 < nums2Size) {
      nums[i] = nums2[point2];
      point2++;
    } else if (point2 == nums2Size && point1 < nums1Size) {
      nums[i] = nums1[point1];
      point1++;
    }
  }

  for (int i = 0; i < numsSize; i++)
    printf("%d ", nums[i]);
  printf("\n");

  int half_1 = numsSize % 2;
  int half_2 = numsSize / 2;
  if (half_1) {
    return nums[half_2];
  } else {
    printf("\n%d\n", nums[half_2 - 1]);
    return (((double)nums[half_2] + (double)nums[half_2 - 1]) / (double)2);
  }
}