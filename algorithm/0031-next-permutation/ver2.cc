static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

namespace yuuki {
namespace detail {
static const constexpr size_t __bsearch_thrd = 16;
template <typename RandAccIter>
RandAccIter bsearch_last_lager_than(RandAccIter first, RandAccIter last, RandAccIter target) {
  RandAccIter saved = last;
  while (first < last) {
    RandAccIter mid = first + (last - first) / 2;
    if (not(*target < *mid)) {
      last = mid;
    } else if (std::next(mid) != last and *target < *std::next(mid)) {
      first = std::next(mid);
    } else {
      return mid;
    }
  }
  return saved;
}
}  // namespace detail

template <typename BidirIter>
bool next_permutation(BidirIter first, BidirIter last) {
  using category = typename std::iterator_traits<BidirIter>::iterator_category;
  static_assert(std::is_base_of<std::bidirectional_iterator_tag, category>::value,
      "bidirectional_iterator required!");
  if (first == last or std::next(first) == last) {
    return false;
  } else /* lbi */;
  BidirIter i = std::prev(last);
  while (true) {
    BidirIter ii = i;
    --i;
    if (*i < *ii) {
      BidirIter j = last;
      if (std::is_same<std::random_access_iterator_tag, category>::value and
          std::distance(ii, last) > detail::__bsearch_thrd) {
        j = detail::bsearch_last_lager_than(ii, last, i);
      } else {
        do {
          --j;
        } while (not(*i < *j));
      }
      std::iter_swap(i, j);
      std::reverse(ii, last);
      return true;
    }
    if (i == first) {
      std::reverse(first, last);
      return false;
    }
  }
}
}  // namespace yuuki

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    yuuki::next_permutation(nums.begin(), nums.end());
  }
};

