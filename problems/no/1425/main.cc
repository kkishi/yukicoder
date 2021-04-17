#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> b = a;
  sort(all(b));
  int j = n - 1;
  while (j >= 0 && b[j] == a[j]) --j;
  ++j;
  int ans = j;
  dbg(j);
  rep(i, j) if (a[i] + 1 < a[(i + 1) % j])-- ans;
  wt(ans);
}
