// 题目：https: // leetcode.cn/problems/roman-to-integer

int getvalue(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
  return 0;
}

int romanToInt(char *s) {
  int output = 0;
  int size = strlen(s);
  int i = 0;

  while (i < size) {
    int now = getvalue(s[i]);
    int next = 0;
    if (i + 1 < size)
      next = getvalue(s[i + 1]);
    if (now < next) {
      output += next - now;
      i += 2;
    } else {
      output += now;
      i += 1;
    }
  }
  return output;
}