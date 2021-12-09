#include <stdio.h>

float bathForThisUnit(int unit) {
  if (0 < unit && unit <= 15) {
    return 2.3488;
  } else if (16 <= unit && unit <= 25) {
    return 2.9882;
  } else if (26 <= unit && unit <= 35) {
    return 3.2405;
  } else if (36 <= unit && unit <= 100) {
    return 3.6237;
  } else if (101 <= unit && unit <= 150) {
    return 3.7171;
  } else if (151 <= unit && unit <= 400) {
    return 4.2218;
  } else if (401 <= unit) {
    return 4.4217;
  } else {
    return 0;
  }
}

float calculatePay(int unit) {
  float pay = 0;
  for (int i = 1; i <= unit; i++) {
    pay += bathForThisUnit(i);
  }
  return pay;
}

int main() {
  int unit;
  printf("Electric power (unit) = ");
  scanf("%d", &unit);
  printf("Pay = %.2f Baht\n", calculatePay(unit));
  return 0;
}