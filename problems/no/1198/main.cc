#include <bits/stdc++.h>

#include "i128.h"
#include "yukicoder.h"

bool Solve(i128 n) { return n != 1 && n != 2 && n != 4 && (n % 2 || !(n % 4)); }

void Main() {
  rd(i128, n);
  wt(Solve(n) ? 1 : -1);
}
