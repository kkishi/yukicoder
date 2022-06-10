#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e % m];
  int ans = 0;
  if (mp[0]) ++ans;
  if (even(m) && mp[m / 2]) ++ans;
  each(k, v, mp) {
    if (k == 0 || k * 2 == m) continue;
    int u = mp[m - k];
    if (u == 0 || v > u || (v == u && k < (m - k))) ans += v;
  }
  wt(ans);
}
