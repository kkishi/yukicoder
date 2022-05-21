#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  rep(n) {
    strings(s);
    int i = 0;
    while (i < sz(s) && s[i] == '0') ++i;
    if (i == sz(s)) {
      wt(0);
    } else {
      wt(s.substr(i));
    }
  }
}
