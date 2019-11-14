#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool queryString(const std::string& S, int32_t N) {
    for (int i = N; i != N / 2; --i) {  // not that: 2 * i == (i << 1)
      std::string binary = std::bitset<32>(i).to_string();
      if (S.find(binary.substr(binary.find("1"))) == std::string::npos) {
        return false;
      }
    }
    return true;
  }
};

