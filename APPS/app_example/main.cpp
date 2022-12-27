// Copyright 2022 Marina Usova

#include <stdio.h>
#include "../../LIBS/lib_example/example.h"

void main() {
  int a = 1, b = 4;
  float result;

  result = division(a, b);

  printf("%d / %d = %.2f\n", a, b, result);
}
