// 题目：https://leetcode.cn/problems/longest-common-prefix

char *longestCommonPrefix(char **strs, int strsSize) {
  char *s = (char *)malloc(200 * sizeof(char));
  int size = 201, point = 0;
  int isOK = 0;
  char c;
  if (strsSize != 1) {
    for (int i = 0; i < strsSize; i++) {
      if (size > strlen(strs[i]))
        size = strlen(strs[i]);
    }
    while (point < size) {
      for (int a = 0; a < strsSize; a++) {
        if (a + 1 == strsSize)
          break;
        if (strs[a][point] == strs[a + 1][point]) {
          isOK = 1;
          c = strs[a][point];
        } else {
          isOK = 0;
          break;
        }
      }
      if (isOK)
        s[point] = c;
      else
        break;
      point++;
    }
    s[point] = '\0';
    return s;
  } else
    return strs[0];
}