#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<int> a(n), b(m);
  cin >> a >> b;
  int ans = 0;
  each(ai, a) each(bj, b) {
    ans += (ai - 1) * (bj + 1) + gcd(ai, bj) + 1;
    ans %= int(1e9 + 7);
  }
  wt(ans);
}
