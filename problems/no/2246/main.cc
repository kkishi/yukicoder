#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  --n;
  int cnt = 0;
  rep(a, 1, 10) rep(b, a + 1, 10) {
    if (n % 36 == cnt) {
      string ans;
      ans += (char)('0' + a);
      ans += (char)('0' + b);
      rep(n / 36) ans += (char)('0' + b);
      wt(ans);
      return;
    }
    ++cnt;
  }
}
