// 题目：https://leetcode.cn/problems/reverse-integer

int reverse(int x) {
  int top = 2147483647;
  int low = -2147483648;

  int PX[11] = {0};
  int output = 0;

  while (x != 0) {
    int pop = x % 10;
    x /= 10;

    if (output > 214748364 || (output == 214748364 && pop > 7))
      return 0;
    if (output < -214748364 || (output == -214748364 && pop < -8))
      return 0;

    output = output * 10 + pop;
  }

  return output;
}