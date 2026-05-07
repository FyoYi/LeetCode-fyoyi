// 题目：https://leetcode.cn/problems/string-to-integer-atoi

int myAtoi(char *s) {
  long output = 0;
  int size = strlen(s);
  printf("%d", size);
  int sign = 1;
  int i = 0;
  while (s[i] == ' ')
    i++;
  if (s[i] == '+') {
    i++;
    sign = 1;
  } else if (s[i] == '-') {
    i++;
    sign = -1;
  }
  if (i >= size) {
    if (output > INT_MAX) {
      if (sign == 1)
        return INT_MAX;
      return INT_MIN;
    }
    return sign * output;
  }
  while (s[i] >= '0' && s[i] <= '9') {
    if (i >= size)
      break;
    int num = s[i] - '0';
    if (10 * output > INT_MAX) {
      if (sign == 1)
        return INT_MAX;
      return INT_MIN;
    }
    output = 10 * output + num;
    i++;
  }
  if (output > INT_MAX) {
    if (sign == 1)
      return sign * INT_MAX;
    return INT_MIN;
  }
  return sign * output;
}