#include "std_lib.h"

int div(int a, int b) {
  int sign = 1;
  int result = 0;

  if (a < 0) {
    a = -a;
    sign *= -1;
  }

  if (b < 0) {
    b = -b;
    sign *= -1;
  }

  while (a >= b) {
    a -= b;
    result++;
  }

  return sign * result;
}

int mod(int a, int b) {
  int sign = 1;
  if (a < 0) {
    a = -a;
    sign = -1;
  }
  if (b < 0) b = -b;
  while (a >= b) a -= b;
  return sign * a;
}

bool strcmp(char *str1, char *str2) {
  while (*str1 && *str2) {
    if (*str1 != *str2) return 0;
    str1++;
    str2++;
  }
  return *str1 == *str2;
}

void strcpy(char *dst, char *src) {
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

void clear(byte *buf, unsigned int size) {
  unsigned int i;
  for (i = 0; i < size; i++) buf[i] = 0;
}

void atoi(char *str, int *num) {
  int i = 0;
  int sign = 1;
  *num = 0;

  if (str[0] == '-') {
    sign = -1;
    i++;
  }

  while (str[i] >= '0' && str[i] <= '9') {
    *num = *num * 10 + (str[i] - '0');
    i++;
  }

  *num *= sign;
}

void itoa(int num, char *str) {
  int i = 0, isNeg = 0, j;
  char temp[64];

  if (num == 0) {
    str[0] = '0';
    str[1] = '\0';
    return;
  }

  if (num < 0) {
    isNeg = 1;
    num = -num;
  }

  while (num != 0) {
    int digit = mod(num, 10);
    temp[i++] = digit + '0';
    num = div(num, 10);
  }

  if (isNeg) temp[i++] = '-';

  for (j = 0; j < i; j++) {
    str[j] = temp[i - j - 1];
  }

  str[i] = '\0';
}
