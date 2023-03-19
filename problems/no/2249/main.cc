#include <bits/stdc++.h>

#include "totient.h"
#include "yukicoder.h"

void Main() {
  const int N = 10000000;
  V<int> totient = Totient(N);
  V<int> ans(N + 1);
  rep(i, 2, N + 1) ans[i] = ans[i - 1] + ((i - 1) * 2 - totient[i]);
  ints(t);
  rep(t) {
    ints(n);
    wt(ans[n]);
  }
}
