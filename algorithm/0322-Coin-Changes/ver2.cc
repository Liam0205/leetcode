static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
} ();

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    } else {
      std::sort(coins.begin(), coins.end(), std::greater<int>());
      int res = googol;
      size_t idx;
      for (idx = 0; idx < coins.size() and coins[idx] > amount; ++idx) { ; }
      dfs(amount, coins, idx, 0, &res);
      return (res == googol) ? -1 : res;
    }
  }

 private:
  static const constexpr int googol = std::numeric_limits<int>::max();  // LOL

  void dfs(const int amount, const vector<int>& coins, const size_t idx, const int base, int* pr) {
    if (idx >= coins.size()) { return; }
    const int coin = coins[idx];
    if (amount % coin == 0) {
      *pr = std::min(*pr, base + amount / coin);
    } else {
      for (int i = amount / coin; i >= 0 and base + i < *pr - 1; --i) {
        dfs(amount - i * coin, coins, idx + 1, base + i, pr);
      }
    }
  }
};

