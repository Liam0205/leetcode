#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int maxNumberOfBalloons(const std::string& text) {
    size_t counters[5];
    std::fill(std::begin(counters), std::end(counters), 0);
    for (const char c : text) {
      switch(c) {
        case 'b':
          ++counters[0]; break;
        case 'a':
          ++counters[1]; break;
        case 'n':
          ++counters[2]; break;
        case 'l':
          ++counters[3]; break;
        case 'o':
          ++counters[4]; break;
        default:
          break;
      }
    }
    counters[3] /= 2;
    counters[4] /= 2;
    return *std::min_element(std::begin(counters), std::end(counters));
  }
};

