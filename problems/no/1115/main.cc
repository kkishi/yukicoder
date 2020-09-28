#include <bits/stdc++.h>

#include "bit.h"
#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<int> c(n);
  rep(i, n) c[a[i] - 1] = i;
  V<int> d(n);
  rep(i, n) d[i] = c[b[i] - 1];

  BIT<int> bit(n);
  int ans = 0;
  rep(i, n) {
    ans += bit.Sum(n - 1) - bit.Sum(d[i]);
    bit.Add(d[i], 1);
  }
  wt(ans);
}
