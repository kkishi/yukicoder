#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  int ans = 0;
  rep(t, 100) rep(g, t + 1) rep(pg, 100) if (t * 5 + g * 2 + pg * 3 == n)++ ans;
  wt(ans);
}
