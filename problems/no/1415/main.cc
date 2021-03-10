#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  strings(n);
  if (n[0] == '-') {
    wt(0);
    return;
  }
  if (sz(n) <= 2) {
    wt(0);
    return;
  }
  wt(n.substr(0, sz(n) - 2));
}
