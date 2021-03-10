#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(i, n + 1) {
    int x = i;
    int y = 1;
    while (x) {
      y *= x % 10;
      x /= 10;
    }
    if (y > 0 && y % 100 == 0) ++ans;
  }
  wt(ans);
}
