// 题目：https://leetcode.cn/problems/longest-substring-without-repeating-characters

int lengthOfLongestSubstring(char *s) {
  int output = 0;
  int max = 0;
  int num = strlen(s);
  char hc[100000];
  int left = 0;
  int right = 0;

  for (int i = 0; i < num; i++) {
    for (int x = left; x < right; x++) {
      if (hc[x] == s[i]) {
        left = x + 1;
        break;
      }
    }
    output = right - left + 1;
    if (output > max)
      max = output;
    hc[right] = s[i];
    right++;
  }

  return max;
}