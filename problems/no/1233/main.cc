#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  const int N = *max_element(all(a));
  int tot = accumulate(all(a), int(0));

  V<int> b(N + 1);
  each(e, a)++ b[e];

  V<int> dx(N + 1);
  int ans = 0;
  int x = 0;
  rep(i, 1, N + 1) {
    ans += b[i] * tot;
    for (int j = i; j <= N; j += i) {
      dx[j] += i * b[i];
    }
    x += dx[i];
    ans -= x * b[i];
  }
  wt(ans);
}
