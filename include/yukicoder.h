#include <boost/hana/functional/fix.hpp>

#include "macros.h"

void Main();

int main() {
  Main();
  return 0;
}

const auto& Fix = boost::hana::fix;

using namespace std;

#define int i64
