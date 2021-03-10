#include <boost/hana/functional/fix.hpp>
#include <iomanip>

#include "macros.h"

void Main();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}

const auto& Fix = boost::hana::fix;

using namespace std;

#define int i64
