static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool isValid(const std::string& s) {
    std::stack<char> stk;
    for (const char c : s) {
      if (stk.empty()) {
        stk.push(c);
      } else if (isPair(stk.top(), c)) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }
    return stk.empty();
  }

  inline bool isPair(const char lhs, const char rhs) const {
    return (lhs == '(' and rhs == ')' or lhs == '[' and rhs == ']' or lhs == '{' and rhs == '}');
  }
};

