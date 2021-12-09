// Copyright (c) 2021 Patsagorn Y.
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

float calculateCoEfficiate(int n, int r) {
  return factorial(n) / (factorial(n - r) * factorial(r));
}

int main() {
  int n = 10;
  for (int i = 0; i < n; i++) {
    printf("result : %f\n", calculateCoEfficiate(n, i));
  }
  return 0;
}