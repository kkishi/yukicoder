#include <bits/stdc++.h>

#include "yukicoder.h"

void Main() {
  V<string> s(3);
  cin >> s;
  string t = accumulate(s);
  wt(t == "#.#.#.#.#" || t == ".#.#.#.#.");
}
