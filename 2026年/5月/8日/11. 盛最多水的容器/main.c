// 题目：https://leetcode.cn/problems/container-with-most-water

int min(int a, int b) {
  if (a > b)
    return b;
  return a;
}

int maxArea(int *height, int heightSize) {
  int left = 0;
  int right = heightSize - 1;
  int max_area = 0;
  int area, weigt;

  for (int i = 0; i < heightSize; i++) {
    weigt = right - left;
    area = weigt * min(height[left], height[right]);
    if (area > max_area)
      max_area = area;
    if (height[left] > height[right])
      right--;
    else
      left++;
  }

  return max_area;
}