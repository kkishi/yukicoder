#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int ans = 0;
  int i = 0;
  while (i < n) {
    auto win = [&](int i) {
      int c = b[i], d = b[i + 1];
      if (c < d) swap(c, d);
      return a[i] + c < a[i + 1] + d;
    };
    int j = i;
    while (j + 1 < n && win(j)) ++j;
    ans += (j - i) * (j - i + 1) / 2;
    i = j + 1;
  }
  wt(ans);
}
