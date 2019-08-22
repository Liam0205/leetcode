static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
} ();

class Solution {
 public:
  int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, googol);
    dp[0] = 0;

    for (const int& coin : coins) {
      for (int i = coin; i < amount + 1; ++i) {
        if (dp[i - coin] != googol) {
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    return (dp[amount] == googol) ? -1 : dp[amount];
  }

 private:
  static const constexpr int googol = std::numeric_limits<int>::max();  // LOL
};

