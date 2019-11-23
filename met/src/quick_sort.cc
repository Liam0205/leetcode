#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <list>
#include <forward_list>

namespace {
namespace details {
template <typename BidirIt>
BidirIt swap_and_return(BidirIt pivot, BidirIt first, std::bidirectional_iterator_tag) {
  --first;
  std::iter_swap(pivot, first);
  return first;
}

template <typename ForwardIt>
ForwardIt swap_and_return(ForwardIt pivot, ForwardIt first, std::forward_iterator_tag) {
    ForwardIt it;
    for (it = pivot; std::next(it) != first; ++it);
    std::iter_swap(pivot, it);
    return it;
}

template <typename ForwardIt,
          typename Category = typename std::iterator_traits<ForwardIt>::iterator_category,
          typename Value = typename std::iterator_traits<ForwardIt>::value_type,
          typename BinaryPred = std::less<Value>>
ForwardIt partition(ForwardIt first, ForwardIt last, ForwardIt pivot,
                    BinaryPred comp = BinaryPred()) {
  static_assert(std::is_base_of<std::forward_iterator_tag, Category>::value,
      "Iter must be ForwardIt!");

  std::iter_swap(first, pivot);
  pivot = first++;

  auto less = std::bind(comp, std::placeholders::_1, *pivot);

  first = std::find_if_not(first, last, less);

  if (first != last) {
    for (ForwardIt i = std::next(first); i != last; ++i) {
      if (less(*i)) {
        std::iter_swap(i, first);
        ++first;
      }
    }
  }

  return swap_and_return(pivot, first, Category());
}
}  // namespace details

template <typename ForwardIt,
          typename Value = typename std::iterator_traits<ForwardIt>::value_type,
          typename BinaryPred = std::less<Value>>
void quicksort(ForwardIt first, ForwardIt last, BinaryPred comp = BinaryPred()) {
  while (std::distance(first, last) > 1) {
    ForwardIt cut = details::partition(first, last, first, comp);
    quicksort(std::next(cut), last, comp);
    last = cut;
  }
}
}  // namespace

int main() {
  std::vector<int> v{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};

  std::for_each(v.begin(), v.end(), [&](auto e) { std::cout << e << ' '; });
  std::cout << std::endl;
  quick_sort(v.begin(), v.end(), std::less<int>());
  std::for_each(v.begin(), v.end(), [&](auto e) { std::cout << e << ' '; });
  std::cout << std::endl;

  return 0;
}
