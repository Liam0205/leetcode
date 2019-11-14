static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    const size_t sz = deck.size();
    if (sz < 2) { return deck; }
    std::sort(deck.begin(), deck.end(), std::greater<int>());
    std::deque<int> dq;
    for (int i = 0; i != sz; ++i) {
      if (not dq.empty()) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      dq.push_front(deck[i]);
    }
    return std::vector<int>{dq.begin(), dq.end()};
  }
};

