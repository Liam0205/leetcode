#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int scoreOfParentheses(const std::string& S) {
    std::stack<int> ss;
    int score = 0;
    for (const char c : S) {
      if (c == '(') {
        ss.push(score);  // push outer level score into score_stack
        score = 0;       // clear score for recording inner level
      } else {
        // equiv: `score += ss.top() + std::max(score, 1);`
        if (score == 0) {
          score = ss.top() + 1;
        } else {
          score = ss.top() + 2 * score;
        }
        ss.pop();        // exit inner level.
      }
    }
    return score;
  }
};

