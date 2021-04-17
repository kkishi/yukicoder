#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  if (n == 0) {
    wt(9, 1);
  } else {
    wt(8 + 9 * 2 * n, 1);
  }
}
