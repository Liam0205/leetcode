#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <string>

namespace yuuki {
template <typename BidirIt,
          typename Value = typename std::iterator_traits<BidirIt>::value_type,
          typename BinPred = std::less<Value>>
bool next_permutation(BidirIt first, BidirIt last, BinPred comp = BinPred()) {
  if (first == last or first == std::prev(last)) { return false; }
  BidirIt valley = std::prev(last);

  while (true) {
    BidirIt peak, i;

    peak = valley;
    if (comp(*--valley, *peak)) {
      i = last;
      while (not comp(*valley, *--i));
      std::iter_swap(valley, i);
      std::reverse(peak, last);
      return true;
    }
    if (valley == first) {
      std::reverse(first, last);
      return false;
    }
  }
}
}  // namespace yuuki

int main() {
  std::string s = "1223";
  do {
    std::cout << s << std::endl;
  } while (yuuki::next_permutation(s.begin(), s.end()));

  return 0;
}
