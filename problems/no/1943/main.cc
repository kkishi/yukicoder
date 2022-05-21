#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  ints(n);
  strings(s);
  int i = n;
  string agct = "AGCT";
  while (i - 1 >= 0) {
    char c = s[i-1];
    if (agct.find(c) != string::npos) break;
    --i;
  }
  wt(i);
}
