// https://leetcode.cn/problems/divide-two-integers

class Solution {
public:
  int divide(int dividend, int divisor) {
    long long a;
    long long b;
    int fu = 0;

    a = dividend;
    b = divisor;

    if (a < 0) {
      a = -a;
      fu++;
    }

    if (b < 0) {
      b = -b;
      fu++;
    }

    long long output = 0;
    long long b5 = b + b + b + b + b;
    long long b10 = b5 + b5;
    long long b20 = b10 + b10;
    long long b100 = b20 + b20 + b20 + b20 + b20;
    long long b1000 =
        b100 + b100 + b100 + b100 + b100 + b100 + b100 + b100 + b100 + b100;
    long long b10000 = b1000 + b1000 + b1000 + b1000 + b1000 + b1000 + b1000 +
                       b1000 + b1000 + b1000;

    while (a >= b10000) {
      a = a - b10000;
      output += 10000;
    }
    while (a >= b1000) {
      a = a - b1000;
      output += 1000;
    }
    while (a >= b100) {
      a = a - b100;
      output += 100;
    }
    while (a >= b20) {
      a = a - b20;
      output += 20;
    }
    while (a >= b10) {
      a = a - b10;
      output += 10;
    }
    while (a >= b) {
      a = a - b;
      output += 1;
    }

    if (fu == 0) {
      if (output > INT_MAX)
        output = INT_MAX;
      return output;
    }
    if (fu == 1) {
      return -output;
    } else {
      if (output > INT_MAX)
        output = INT_MAX;
      return output;
    }
  }
};