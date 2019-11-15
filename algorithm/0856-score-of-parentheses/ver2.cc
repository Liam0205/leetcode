#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class solution {
 public:
  int scoreOfParentheses(const std::string& s) {
    size_t level = 0;
    int    score = 0;

    const size_t sz = s.size();
    for (size_t i = 0; i != sz; ++i) {
      if (s[i] == '(') {
        ++level;
      } else {
        --level;
        // thoughts: score is contributed by consective `()`,
        // and doubled by outer levels, respective to the specific `()`.
        // `()` in the most outer level,         i.e. level == 0, result in 1 * 2 ^ 0 score;
        // `()` in the most outer level but one, i.e. level == 1, result in 1 * 2 ^ 1 score;
        // `()` in the most outer level but two, i.e. level == 2, result in 1 * 2 ^ 2 score;
        // and so on.
        if (s[i - 1] == '(') {  // we are meeting `()`.
          score += 1 << level;
        }
      }
    }

    return score;
  }
};

