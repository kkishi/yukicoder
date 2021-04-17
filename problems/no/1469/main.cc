#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  strings(s);
  rep(i, sz(s)) {
    if (i > 0 && s[i] == s[i - 1]) continue;
    cout << s[i];
  }
  cout << endl;
}
