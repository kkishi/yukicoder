#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  sort(all(a), greater{});
  int ans = 0;
  rep(i, n) {
    int j = 2;
    int x = 0;
    while (j < i + 2) {
      ++x;
      j <<= 1;
    }
    ans += x * a[i];
  }
  wt(ans);
}
