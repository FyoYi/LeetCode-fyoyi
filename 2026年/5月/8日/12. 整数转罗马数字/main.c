// 题目：https://leetcode.cn/problems/integer-to-roman

char *intToRoman(int num) {
  int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  char *sign[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                  "XL", "X",  "IX", "V",  "IV", "I"};
  char *output = (char *)malloc(20 * sizeof(char));
  int size = 13, point = 0;

  for (int i = 0; i < size; i++) {
    while (num >= value[i]) {
      char *p = sign[i];
      while (*p != '\0') {
        output[point++] = *p++;
      }
      num -= value[i];
    }
  }
  output[point] = '\0';
  return output;
}