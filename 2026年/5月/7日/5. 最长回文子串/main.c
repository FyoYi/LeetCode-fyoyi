// 题目：https://leetcode.cn/problems/longest-palindromic-substring

void LeftRight(float mid, int *left, int *right) {
  if (floor(mid) == mid) {
    *left = mid - 1;
    *right = mid + 1;
  } else {
    *left = mid - 0.5;
    *right = mid + 0.5;
  }
}

char *longestPalindrome(char *s) {
  int numsSize = strlen(s);
  int left = 0, right = 0, max = 0, MAX = 1;
  int local[2] = {0, 0};

  for (float mid = 0; mid < numsSize; mid += 0.5) {
    LeftRight(mid, &left, &right);

    while (left >= 0 && right < numsSize && s[left] == s[right]) {
      max = right - left + 1;

      if (MAX < max) {
        MAX = max;
        local[0] = left;
        local[1] = right;
      }

      left--;
      right++;
    }
  }

  char *output = malloc((MAX + 1) * sizeof(char));

  for (int i = 0; i < MAX; i++) {
    output[i] = s[local[0] + i];
  }

  output[MAX] = '\0';
  return output;
}