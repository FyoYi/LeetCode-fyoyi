// 题目：https://leetcode.cn/problems/palindrome-number

int tenN(int N) {
  int output = 1;
  if (N > 9)
    return INT_MAX;
  for (int i = 0; i < N; i++) {
    output *= 10;
  }
  return output;
}
bool isPalindrome(int x) {
  if (x == 0)
    return true;
  else if (x < 0)
    return false;
  else if (x > INT_MAX - 7412)
    return false;
  int n = 1;
  while (x / tenN(n)) {
    n++;
  }
  int a = 1;
  int left = (x % (tenN(n - a + 1))) / (tenN(n - a));
  int right = (x % (tenN(a))) / (tenN(a - 1));
  while (left == right) {
    a++;
    left = (x % (tenN(n - a + 1))) / (tenN(n - a));
    right = (x % (tenN(a))) / (tenN(a - 1));
    if (a > (n / 2) + 1)
      return true;
  }
  return false;
}