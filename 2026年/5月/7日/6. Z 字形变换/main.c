// 题目：https://leetcode.cn/problems/zigzag-conversion

void size(int S, int N, int *hang, int *lie) {
  if (N == 1) {
    *lie = 1;
    *hang = S;
    return;
  }
  int cf_num = 2 * (N - 1);
  float cf_time = (float)S / (float)(2 * (N - 1));
  if (floor(cf_time) == cf_time)
    *hang = cf_time * (N - 1);
  else
    *hang = (floor(cf_time + 1) * (N - 1));
  *lie = N;
}

char *convert(char *s, int numRows) {
  if (numRows != 1) {
    int numsSize = strlen(s);
    int hang, lie;
    size(numsSize, numRows, &hang, &lie);
    printf("H:%d L:%d\n", hang, lie);
    char Z[hang][lie];
    for (int x = 0; x < hang; x++) {
      for (int y = 0; y < lie; y++) {
        Z[x][y] = ' ';
      }
    }

    int xx = 0, yy = 0, add = 0;
    int z_0 = 0, z_1 = 0;
    for (int i = 0; i < numsSize; i++) {
      yy += add;
      if (yy == 0)
        add = 1;
      else if (yy == (lie - 1))
        add = -1;
      if ((z_0++) >= numRows) {
        xx++;
        if (z_1++ == (numRows - 2))
          z_0 = 1;
      } else {
        z_1 = 0;
      }
      Z[xx][yy] = s[i];
    }
    char *output = (char *)malloc((numsSize + 1) * sizeof(char));
    int n = 0;
    for (int y = 0; y < lie; y++) {
      for (int x = 0; x < hang; x++) {
        if (Z[x][y] != ' ') {
          output[n] = Z[x][y];
          n++;
        }
      }
    }
    output[numsSize] = '\0';
    return output;
  } else
    return s;
}